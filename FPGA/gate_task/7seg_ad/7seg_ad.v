module top(
    input A,
    input B,
    input C,

    output reg segA,
    output reg segB,
    output reg segC,
    output reg segD,
    output reg segE,
    output reg segF,
    output reg segG
);

wire F;

// Minimized POS Expression
assign F = (~B | C) & (~A | C);

always @(*)
begin
    if(F)
    begin
        // Display 1
        // Common Anode (LOW = ON)

        segA = 1;
        segB = 0;
        segC = 0;
        segD = 1;
        segE = 1;
        segF = 1;
        segG = 1;
    end
    else
    begin
        // Display 0

        segA = 0;
        segB = 0;
        segC = 0;
        segD = 0;
        segE = 0;
        segF = 0;
        segG = 1;
    end
end

endmodule
