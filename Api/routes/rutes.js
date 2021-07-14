'use strict'

/** CONFIGURACION DE RUTAS
 * @Observarions : Se crean las rutas necesarias para la api, para los controladores
 * agreagarlos en la carpeta de controller.
 */

const express = require('express');

const router = express.Router();

router.get('login', (req, res) =>{
  console.log("Acceso a api");
});

module.exports = router;
