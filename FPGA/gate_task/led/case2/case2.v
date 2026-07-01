module top(
    output led
);

wire a, b, c;
wire f;

assign a = 1'b0;
assign b = 1'b1;
assign c = 1'b1;

assign f = (~b | c) & (a | ~c);

assign led = f;

endmodule

