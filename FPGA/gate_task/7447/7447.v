module top(
    input A,
    input B,
    input C,

    output reg D3,
    output reg D2,
    output reg D1,
    output reg D0
);

wire F;

// Minimized POS expression
assign F = (~B | C) & (A | ~C);

always @(*)
begin
    if(F)
    begin
        // Display 1
        D3 = 0;
        D2 = 0;
        D1 = 0;
        D0 = 1;
    end
    else
    begin
        // Display 0
        D3 = 0;
        D2 = 0;
        D1 = 0;
        D0 = 0;
    end
end

endmodule
