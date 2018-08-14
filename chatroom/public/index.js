var socket=io();
var countdiv=0;
socket.on("connect",function(){
    socket.emit('greet'); //send to the server
    });
socket.on("greet",function(msg)  //when accept the msg from server,output to the web 
    {
      document.getElementById('msg').innerText=msg;
    
    })
document.addEventListener('DOMContentLoaded',()=>{
  
 var status = document.getElementById("status");
 var online = document.getElementById("online");
 var sendform=document.getElementById("send-form");
 var content=document.getElementById('content');

socket.on('msg',function(data)
    { 
      var msgbox=document.createElement('div');
        msgbox.className="msg";
      var namebox=document.createElement('span');
       namebox.className="name";
       var name=document.createTextNode(data.name);
       var msg=document.createTextNode(data.msg);
       $('#msg').val("");
       namebox.appendChild(name);
       msgbox.appendChild(namebox);
       msgbox.appendChild(msg);
       content.appendChild(msgbox);
   countdiv++;
      if(countdiv>12)
      {
        var elmnt = document.getElementById("content");
        elmnt.scrollTop += 1000;
      }  

    });
sendform.addEventListener("submit",function(e)
{   
  e.preventDefault();
  var formdata={};
  var formchild=sendform.children;

  for(var i=0;i<sendform.childElementCount;i++)
 {
   var child=formchild[i];
   if(child.name!="")
   formdata[child.name]=child.value;  
 }
  socket.emit('send',formdata);
  
});// end sendform
  socket.on('connect',function(){
  status.innerText="connected";   //to display the status of online
  });
  socket.on('disconnect',function(){
   status.innerText="disconnected";
  });
  socket.on("online",function(amount){  //to display the amount of online
   console.log(amount);
    online.innerText=amount;
  }); 
});//end eventlistener









