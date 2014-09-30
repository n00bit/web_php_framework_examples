<?php
/**
 * Created by PhpStorm.
 * User: goruha
 * Date: 01.10.14
 * Time: 2:37
 */

namespace framework;


class Core {

  static function Load() {
    foreach (glob("libraries/*.inc") as $filename)
    {
      include_once $filename;
    }

    foreach (glob("modules/**/*.inc") as $filename)
    {
      include_once $filename;
    }
  }
} 