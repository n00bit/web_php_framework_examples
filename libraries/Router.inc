<?php
/**
 * Created by PhpStorm.
 * User: goruha
 * Date: 01.10.14
 * Time: 2:56
 */

namespace framework;


class Router {

  /**
   * @var Router|null
   */
  static private $__instance = null;


  const GET = 1;
  const POST = 1;


  private $routes;

  private function __construct() {
    $this->routes = array(
      self::GET => array(),
      self::POST => array(),
    );
  }

  /**
   * @return Router
   */
  static public function Instance() {
    if (is_null(self::$__instance)) {
      self::$__instance = new Router();
    }
    return self::$__instance;
  }



  public function Get($pattern, $class, $args) {
    $this->Routes(self::GET, $pattern, $class, $args);
  }

  public function Post($pattern, $class, $args) {
    $this->Routes(self::POST, $pattern, $class, $args);
  }

  private function Routes($method, $pattern, $class, $args) {
    $this->routes[$method][$pattern] = array('class' => $class, 'args' => $args);
  }

  public function run() {
    $controller = $this->fetch();
    return $controller;
  }


  private function fetch() {
    $this->sort_routes();
    $method = $_SERVER['REQUEST_METHOD'] == 'POST' ? self::POST : self::GET;
    $matches = array();
    foreach ($this->routes[$method] as $pattern => $data) {
      if (preg_match_all("/$pattern/", $_GET['q'], $matches) !== false) {
        $params = array();
        foreach($data['args'] as $num => $id) {
          $params[$num] = current($matches[$id]);
        }
        $contoller = new $data['class']();
        call_user_func_array(array($contoller, "init"), $params);
        return $contoller;
      }
      $matches = array();
    }
    return new NotFound();
  }

  private function sort_routes() {

    $func = function($a, $b){
      return strlen($b) - strlen($a);
    };

    uksort($this->routes[self::GET] , $func);
    uksort($this->routes[self::POST] , $func);
  }

}