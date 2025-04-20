import re

def process_intermediate_code(input_string, symbol_table, literal_table):
    try:
        lines = input_string.strip().split("\n")
        for line in lines:
            line = line.strip()
            if not line:
                continue  # Skip empty lines

            # Extract components using regex
            parts = re.findall(r'\((\w+), (\d+)\)|(\d+)', line)
            output = []

            if parts:
                if parts[0][0] == "IS":
                    opcode = parts[0][1]
                    output.append(opcode)

                # Process remaining parts
                for part in parts[1:]:
                    if part[0] == 'S':  # Symbol reference
                        sym_index = int(part[1])
                        output.append(str(symbol_table.get(sym_index, '-')))
                    elif part[0] == 'L':  # Literal reference
                        lit_index = int(part[1])
                        output.append(str(literal_table.get(lit_index, '-')))
                    elif part[2]:  # Direct operand (like a register or constant)
                        output.append(part[2])

                print(" ".join(output))

    except Exception as e:
        print(f"Error: {e}")

# Sample Symbol Table
symbol_table = {
    1: 107,
    2: 101,
    3: 504,
    4: 507,
    5: 101,
    6: 500
}

# Sample Literal Table
literal_table = {
    1: 105,
    2: 106,
    3: 502,
    4: 504,
    5: 508
}

# Input String
input_string = """
(IS, 01) 01 (S, 01)
(IS, 09) - (S, 03)
(IS, 02) 02 (L, 04)
(IS, 04) 03 (S, 02)
(IS, 08) - (L, 05)
"""

# Run the function
process_intermediate_code(input_string, symbol_table, literal_table)



//output

01 01 107
09 504
02 02 504
04 03 101
08 508










import re

def process_intermediate_code(input_string, symbol_table, literal_table):
    try:
        lines = input_string.strip().split("\n")
        for line in lines:
            line = line.strip()
            if not line:
                continue  # Skip empty lines

            parts = re.findall(r'\((\w+), (\d+)\)|(\d+)', line)
            output = []

            if parts:
                if parts[0][0] == "IS":
                    opcode = parts[0][1]
                    output.append(opcode)

                for part in parts[1:]:
                    if part[0] == 'S':
                        sym_index = int(part[1])
                        output.append(str(symbol_table.get(sym_index, '-')))
                    elif part[0] == 'L':
                        lit_index = int(part[1])
                        output.append(str(literal_table.get(lit_index, '-')))
                    elif part[2]:
                        output.append(part[2])

                print(" ".join(output))
    except Exception as e:
        print(f"Error: {e}")

# Sample Symbol Table
symbol_table = {
    1: 107,
    2: 101,
    3: 504,
    4: 507,
    5: 101,
    6: 500
}

# Sample Literal Table
literal_table = {
    1: 105,
    2: 106,
    3: 502,
    4: 504,
    5: 508
}

# 🧾 Get User Input for Intermediate Code
print("Enter intermediate code line by line (press Enter on empty line to finish):")
user_lines = []
while True:
    line = input()
    if line.strip() == "":
        break
    user_lines.append(line)

input_string = "\n".join(user_lines)

# ▶️ Run the function
process_intermediate_code(input_string, symbol_table, literal_table)




output

input string


(IS, 01) 01 (S, 01)
(IS, 09) - (S, 03)
(IS, 02) 02 (L, 04)
(IS, 04) 03 (S, 02)
(IS, 08) - (L, 05)

ans:-

01 01 107
09 504
02 02 504
04 03 101
08 508
