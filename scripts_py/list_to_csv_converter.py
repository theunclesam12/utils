import csv

# Helper function that takes a variable containing dictionary of lists and converts + writes them into rows on a csv.

p1 = [-5, -60, -120, -45, 100, 0]
p2 = [-5, -110, -50, -90, 100, 0]
p3 = [-5, -110, -50, -90, 180, 0]
p4 = [-5, -120, -75, -180, 180, -10]
data = {
    "p1": p1,
    "p2": p2,
    "p3": p3,
    "p4": p4
}

# Output CSV file name
output_file = "../output.csv"

with open(output_file, mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["Name", "Values"])  # Header row

    for name, values in data.items():
        writer.writerow([name] + values)

print(f"Data has been written to {output_file}")
