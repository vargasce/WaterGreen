'use strict'

//CONFIGURACION SERVICIO API
const express = require('express');
const bodyParser = require("body-parser");
const app = express();
const multiParty = require("connect-multiparty");

/** CONFIGURACION DE RUTAS **/
console.log("Importanto rutas del sistema...");
const routes = require("./routes/rutes");

/** CONFIGURACION DE MIDDLEWARE 
 * @Observation : Esta configuracion es global, cualquier dato llegado se ejecuta el middleware 
 * y parsea la data a tipo json.
 * @extends : en modo false es unca configuracion necesario para utilizar el bodyParser
 */
app.use(bodyParser.urlencoded({extended : false}));
app.use(bodyParser.json);
app.use(multiParty());
app.use(require("express-useragent").express());


/** CONFIGURACION DE CORS **/
console.log("Configuracion de CORS ...");
app.use( ( req, res, next ) =>{
  res.header('Access-Control-Allow-Origin', '*'); //En una app real en lugar del * se deberia ingresar el url permitidas
  res.header('Access-Control-Allow-Headers', 'Authorization, X-API-KEY, Origin, X-Requested-With, Content-Type, Accept, Access-Control-Allow-Request-Method');
  res.header('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, DELETE');
  res.header('Allow', 'GET, POST, OPTIONS, PUT, DELETE');
  next();
});

/** EXPORTAMOS RUTAS DE LA API**/
app.use('./api',routes);

module.exports = app;
