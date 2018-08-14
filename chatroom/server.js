const express = require('express');
const app = express();
const server = require('http').Server(app);
const io = require('socket.io')(server);
app.use(express.static(__dirname + '/public'))
let count=0;
server.listen(10065, () => {
    console.log("Server Started. http://localhost:3000");
    });
app.get('/', (req,res) => {
 res.send('connected!')
   });  //to display the status on server
io.on('connection',(socket)=>{
  count++;
  io.emit('online',count);
  socket.on('disconnect',()=>{
    count=(count<0)?0:count-=1;
    io.emit('online',count);
  });//socket
  socket.on('send',(msg)=>
{    
 io.emit('msg',msg);   
      
 });
}); //io
 












