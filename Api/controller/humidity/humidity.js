'use strict'

const con = require('../../connectDB/connectiondb');

const controller = {

  setHumidity : ( req, res ) =>{
    let data = req.body;
    let sql = `${data}`;
    con.insert( sql, ( error, result ) =>{
      if( !error ){
        res.status(200).send({ 'error': '', 'ResultSet' : result });
      }else{
        res.status(500).send({ 'error' : `Error al insertar humidity : ${error}`, 'ResultSet' : result });
      }
    });
  },

  getHumidity : ( req, res ) => {
    let data = req.body;
    let sql = `${data}`;
    con.select( sql, ( error, result ) =>{
      if( !error ){
        res.status(200).send({ 'error' : '', 'ResultSet' : result });
      }else{
        res.status(500).send({ 'error' : `Error al obtener humidity : ${error}`, 'ResultSet' : result });
      }
    });
  }

}

module.exports = controller;
