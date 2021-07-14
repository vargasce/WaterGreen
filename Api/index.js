'use strict'

const app = require('./app');
const port = "3700";
const host = "localhost";

app.listen(port, host, ()=>{
  console.log(`Servicio Water Green SUCCESS!!, url : ${host}:${port}/api/+controller`);
})
