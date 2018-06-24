const express=require('express');
const app=express();
const port=3000;
app.listen(port);
app.use(express.static(__dirname+"/public"));
var mysql=require('mysql');
var con = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "qw1562435",
  database:"project_database"
});
app.get('/get_data',function(req,res)
{   
  con.connect(function(err) {
  if (err) throw err;
  console.log("Connected!");
  var sql= "INSERT INTO eddiedata (user,studentid,department) VALUES ('"+req.query.user+"','"+req.query.std+"','"+req.query.department+"');" 
  con.query(sql, function (err, result) {
    if (err) throw err;
  });
  });
});


