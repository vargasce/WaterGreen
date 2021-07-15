'use strict'

/** CONFIGURACION DE RUTAS
 * @Observarions : Se crean las rutas necesarias para la api, para los controladores
 * agreagarlos en la carpeta de controller.
 */

const express = require('express');
const Humidity = require('../controller/humidity/humidity');
const router = express.Router();

router.POST('setHumidity', Humidity.setHumidity());
router.POST('getHumidity', Humidity.getHumidity());

module.exports = router;
