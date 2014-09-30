<?php
/**
 * Created by PhpStorm.
 * User: goruha
 * Date: 01.10.14
 * Time: 3:58
 */

namespace framework;
include_once "iController.inc";


class NotFound implements iController{


  public function render() {
    echo "Test";
  }

  public function init() {
    // TODO: Implement init() method.
  }
}