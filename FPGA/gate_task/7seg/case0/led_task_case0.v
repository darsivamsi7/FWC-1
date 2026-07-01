module boolean_display(

    output reg seg_a,
    output reg seg_b,
    output reg seg_c,
    output reg seg_d,
    output reg seg_e,
    output reg seg_f,
    output reg seg_g

);

wire A;
wire B;
wire C;
wire f;

// Fixed inputs
assign A = 1'b0;
assign B = 1'b1;
assign C = 1'b0;

// Minimized PoS expression
assign f = ((~B) | C) & (A | (~C));

always @(*) begin

    if (f == 1'b1)
    begin
        // Display 1 (Common Anode)
        seg_a = 1'b1;
        seg_b = 1'b0;
        seg_c = 1'b0;
        seg_d = 1'b1;
        seg_e = 1'b1;
        seg_f = 1'b1;
        seg_g = 1'b1;
    end
    else
    begin
        // Display 0 (Common Anode)
        seg_a = 1'b0;
        seg_b = 1'b0;
        seg_c = 1'b0;
        seg_d = 1'b0;
        seg_e = 1'b0;
        seg_f = 1'b0;
        seg_g = 1'b1;
    end

end

endmodule
