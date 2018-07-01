`timescale 1ns/10ps
module tb;
wire [3:0] sum;
wire c4;
reg [0:3] a;
reg[0:3] b;
reg c0;
adder bitsadder(.a(a),.b(b),.c0(c0),.sum(sum),.c4(c4));

initial begin
	$dumpfile("adder.vcd");
	$dumpvars();
end
 initial begin
a  = 4'h0;
b  = 4'h0;
c0 = 1'b0;
 end
  
always #50  a = a + 1;
always #100 b = a + 1;


endmodule

  
  
     






