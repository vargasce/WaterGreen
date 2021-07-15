'use strict'

const data = {
  host : 'localhost',
  user : 'watergreen',
  password : 'password',
  database : 'watergreen'
};


const conexionDB = ( function() {
  
  var instanciaDB;

  function init() {

		let con = mysql.createConnection(data);

		con.connect( (error)=>{
			if (error) console.log('Error en conexion con DB : ', error);
		}); 

		return {
			request : function (){
				return con;
			},
			close : function (){
				con.end();
			}
		};
	}

	return {
		getInstance : function() {
			if ( !instanciaDB ){
			  instanciaDB = init();
			}
			return instanciaDB;
	  }
	}
})();

module.exports = {
  conexionDB : conexionDB
}
