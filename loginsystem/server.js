const express=require('express');
const app=express();
const port=10065;
app.listen(port);
var mysql=require('mysql');
app.use(express.static(__dirname + '/public'));
var con = mysql.createConnection({    //to connect the database
  host: "localhost",
  user: "uidd2018_groupG",
  password: "webGGdata",
  database: "uidd2018_groupG"
});
app.get('/ajax',function(req,res)  // to create the data of user
    {  
       
    
    
    
    });



con.connect(function(err) {
  if (err) throw err;
  console.log("Connected!");
  var sql = "INSERT INTO customers (name, address) VALUES ('Company Inc', 'Highway 37')";
  con.query(sql, function (err, result) {
    if (err) throw err;
    console.log("1 record inserted");
  });
});



