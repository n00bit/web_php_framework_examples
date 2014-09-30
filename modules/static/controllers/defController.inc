<?php
/**
 * Created by PhpStorm.
 * User: goruha
 * Date: 01.10.14
 * Time: 4:11
 */

namespace framework\static_page\controllers;

use framework\iController;

class defController implements iController {

  public function render() {
    echo 'Login';
  }

  public function init() {
    var_dump(func_get_args());
  }
}