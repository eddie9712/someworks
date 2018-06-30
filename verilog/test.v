//////the module of gate//
`timescale 1ns/100ps
module simple_c(A,B,C,D,E);
output D,E;
input A,B,C;
wire w1;

and #(30)G1(w1,A,B);
not #(10)G2(E,C);
or #(20)G3(D,w1,E);
endmodule
////testbench ////
module t_simple_c;
wire D,E;
reg A,B,C;
/// INSTANCE///
simple_c test(A,B,C,D,E);
//// output to vcd file//
initial 
   begin
 $dumpfile("test.vcd");
 $dumpvars;
end
//input data
initial 
  begin
  A=1'b0;B=1'b0;C=1'b0;
  #100A=1'b1;B=1'b1;C=1'b1;
  end
initial #200 $finish;
endmodule   //end testbench
   
 













 
