




















`timescale 1ns/100ps
`define CYCLE 10

module Montgomery_tb ();

//**************************** wire & reg**********************//
reg clk;
reg [255:0] A;
reg [255:0] B;
reg [255:0] N;
reg n_rst;
reg n_start;

wire [255:0] S;
wire n_ready;
//**************************** module **********************//

Montgomery lalala(.clk(clk),.A(A),.B(B),.N(N),.S(S),.n_rst(n_rst),.n_start(n_start),.n_ready(n_ready));

//**************************** clock gen **********************//
always begin #(`CYCLE/2) clk = ~clk; end

//**************************** initial and wavegen **********************//
initial begin
 $dumpfile("montgomery.vcd");
 $dumpvars;
end

//**************************** testdata **********************//
initial begin
 clk = 1'b0;
 A = 256'd0;
 B = 256'd0;
 N = 256'd0;
 n_rst = 1'b0;
 n_start = 1'b1;
 #1 n_rst = 1'b1;
 A = 256'h4;
 B = 256'h8;
 N = 256'd13;
 #100 n_start = 1'b0;
 #10 n_start = 1'b1;
 #100000 $finish;
end

endmodule
