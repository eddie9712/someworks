var name=""
var mail=""
var department=""
var grade="" 
$(document).ready(function() {
  var depatment=new Vue({
         el:'#department',
         data:{
           	message:' '
                }
            });
   var grade=new Vue({
         el:'#grade',
         data:{
           	message:' '
                }
            });
    var frame2=new Vue({
    el:"#frame2",
    data:{
        delet:true
        }
     })
   var frame1=new Vue({
    l:"#frame1",
    data:{
        delet:true
        }
     })
    $('.o1').click(function(){
    $('.oo1').hide();
   })
  $('#submit').click(function()
{
   name=$('#first_name1').val();
   mail=$('#first_name2').val();
   department=depatment.message;
   grade=grade.message;
   console.log(department+grade)
   $('#name').text(name);
   $('#mail').text(mail);    
   $('#depart').text(department); 
   $('#gra').text(grade); 
   $('#box').hide();
   $('#mask').hide(); 
})
$('#link').click(function()
  { 
      $('#mask').show();
      $('#box').show();
  })
 $('#back').click(function()
{
   $('#box').hide();
   $('#mask').hide();
  })
})

