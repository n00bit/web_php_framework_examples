<?php
/**
 * Created by PhpStorm.
 * User: goruha
 * Date: 01.10.14
 * Time: 4:06
 */

namespace framework\static_page;

use framework\Router;

include_once "controllers/defController.inc";

Router::Instance()->Get('login\/(\d+)', 'framework\static_page\controllers\defController', array(1));
