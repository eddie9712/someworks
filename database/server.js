const express=require('express');
const app=express();
const port=3000;
const bodyParser=require('body-parser')
app.use(bodyParser.json({limit: '50mb'}));
app.use(bodyParser.urlencoded({limit: '50mb', extended: true}));
app.listen(port);
app.use(express.static(__dirname+"/public"));
var mysql=require('mysql');
var temp='';
var temp2='';
var temp3='';
var con = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "qw1562435",
  database:"project_database"
});
app.get('/get_data',function(req,res)
{   
  console.log('hi')
  console.log(req.query);
    var sql= "INSERT INTO eddiedata (user,studentid,department) VALUES ('"+req.query.user+"','"+req.query.std+"','"+req.query.department+"');"   //input user data
  con.query(sql, function (err, result) {
    if (err) throw err;
     
     
});
   var sql2="SELECT * FROM DEPARTMENT WHERE Dept_Code='"+req.query.department+"'";   //return dapartment
 con.query(sql2, function (err, result) {
    if (err) throw err;
     console.log(result[0]['Dept_Name']); 
    
     if(result[0]['Dept_Name']=='工科系')
    {
      res.send('1')
    }
     else if(result[0]['Dept_Name']=='水利系')
    {
      res.send('2')
    }

      
   });
    
   var sql6="SELECT ATLEAST FROM "+req.query.department+";" 
  con.query(sql6, function (err, result) {
    if (err) throw err;
       temp2=result[0]['ATLEAST'];
   });
    var sql7="SELECT SPECIAL FROM "+req.query.department+";" 
  con.query(sql7, function (err, result) {
    if (err) throw err;
       temp3=result[0]['SPECIAL'];
   });
   
});
app.post('/get_check',function(req,res)
{          
   console.log(req.body.feature)

    var sql4="CREATE TABLE TEMP(Cnumber    VARCHAR(50))";    //create table
  con.query(sql4, function (err, result) {
    if (err) throw err;
   });
    for(var j=0;j<req.body.feature.length;j++) 
  { 
   // console.log(req.body.)
    var sql3="INSERT INTO TEMP (Cnumber) VALUES ('"+req.body.feature[j]+"')";
     con.query(sql3,function(err,result){
    if (err) throw err;
     console.log('into')
     });
   }   //end for
    var sql5="SELECT SUM(Credits) FROM COURSE WHERE Cnumber IN (SELECT COURSE.Cnumber FROM COURSE INNER JOIN TEMP ON COURSE.Cnumber=TEMP.Cnumber);"
     con.query(sql5, function (err, result) {
   console.log(result);
   temp=result[0]['SUM(Credits)']
    if (err) throw err;
   res.send("<h1>已修學分:"+temp+"<br>最少系上選修:"+temp2+"<br> 特殊規定:"+temp3+"</h1>");
 });
    var sql8="DROP  TABLE TEMP;"
  con.query(sql8, function (err, result) {
    if (err) throw err;
      
   });

});
app.post('/get_check2',function(req,res)
{ 
  
     console.log('hello')
    var sql4="CREATE TABLE TEMP(Cnumber    VARCHAR(50))";    //create table
  con.query(sql4, function (err, result) {
    if (err) throw err;
   });
    for(var j=0;j<req.body.feature.length;j++)
  {
   // console.log(req.body.)
    var sql3="INSERT INTO TEMP (Cnumber) VALUES ('"+req.body.feature[j]+"')";
     con.query(sql3,function(err,result){
    if (err) throw err;
     console.log('into')
     });
   }   //end for
    var sql5="SELECT SUM(Credits) FROM COURSE WHERE Cnumber IN (SELECT COURSE.Cnumber FROM COURSE INNER JOIN TEMP ON COURSE.Cnumber=TEMP.Cnumber);"
     con.query(sql5, function (err, result) {
   console.log(result);
   temp=result[0]['SUM(Credits)']
    if (err) throw err;
   res.send("<h1>已修學分:"+temp+"<br>最少系上選修:"+temp2+"<br> 特殊規定:"+temp3+"</h1>");
 });
    var sql8="DROP  TABLE TEMP;"
  con.query(sql8, function (err, result) {
    if (err) throw err;

   });

});






