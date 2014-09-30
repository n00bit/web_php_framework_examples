<?php
/**
 * Created by PhpStorm.
 * Api: goruha
 * Date: 01.10.14
 * Time: 2:08
 */
namespace framework;

include_once "bootstrap/core.inc";

Core::Load();

$router = Router::Instance();

$view = $router->run();
$view->render();