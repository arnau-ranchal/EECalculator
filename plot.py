import sys
import matplotlib.pyplot as plt

# Read the entire input from stdin
input_csv = sys.stdin.read().strip()

# Split the input into lines
lines = input_csv.split('\n')

# Prepare a list to hold all sets of values
all_values = []

# Process each line
for line in lines:
    if line.strip():  # Skip empty lines
        values = line.split(',')
        del values[-1]  # Remove the last element
        try:
            values = [float(value) for value in values]
            all_values.append(values)
        except ValueError as e:
            print(f"Error converting values to floats: {e}")
            sys.exit(1)

# Print the received list of values for debugging
for i, values in enumerate(all_values):
    print(f"Received list of values for line {i+1}: {values}")

# Set the desired resolution
width, height = 571, 451  # Specify the width and height in pixels

# Calculate the figure size in inches based on the desired resolution
fig_width = width / 100.0  # Convert pixels to inches
fig_height = height / 100.0  # Convert pixels to inches

# Create a figure with the specified resolution
plt.figure(figsize=(fig_width, fig_height))

# Plot each set of values with a different style
for values in all_values:
    plt.plot(values)

# Save the figure
plt.savefig("C:/Users/TESTER/Documents/TFG1000/fig1.png", transparent=True, dpi=100)
