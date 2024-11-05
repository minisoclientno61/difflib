-- usage

local difflib = require("difflib")
local ret = difflib.sequence_ratio("may the force with you", "may the force be with you")
print("difflib sequence ratio: ", ret)