import matplotlib.pyplot as plt
import os
import sys
from math import ceil

minSNR =    float(sys.argv[1])
maxSNR =    float(sys.argv[2])
ptsSNR =    int  (sys.argv[3])
minRate =   float(sys.argv[4])
maxRate =   float(sys.argv[5])
ptsRate =   int  (sys.argv[6])
minMod =    float(sys.argv[7])
maxMod =    float(sys.argv[8])
ptsMod =    int  (sys.argv[9])

indexRate = int  (sys.argv[10])
indexE0 =   int  (sys.argv[11])
indexMod =  int  (sys.argv[12])
indexSNR =  int  (sys.argv[13])

widXsize  = int  (sys.argv[14]) #size x in pixels of the widget to represent the plots
widYsize  = int  (sys.argv[15]) #size y in pixels of the widget to represent the plots

save      = bool (sys.argv[16])

mode      = int  (sys.argv[17])

my_dpi = 166

# Read the text file
if(mode == 1):
    filename = 'C:/Users/TESTER/Documents/TFG1000/e0_samples_iid_psk.txt'
elif (mode == 2):
    filename = 'C:/Users/TESTER/Documents/TFG1000/e0_samples_cc_psk.txt'
else:
    filename = 'C:/Users/TESTER/Documents/TFG1000/e0_samples_ccomp_psk.txt'

output_dir = 'C:/Users/TESTER/Documents/TFG1000/plots/'
save_dir = 'C:/Users/TESTER/Documents/TFG1000/good_plots/'

with open(filename, 'r') as file:
    lines = file.readlines()

# Parse the data
data = [line.strip().split(',') for line in lines]
data = [(float(rate), float(snr), int(mod), float(e0)) for rate, snr, mod, e0 in data
        if minRate <= float(rate) <= maxRate
        and minMod <= int(mod) <= maxMod
        and minSNR <= float(snr) <= maxSNR]

# Group data by SNR value
grouped = {}
for rate, snr, mod, e0 in data:
    if snr not in grouped:
        grouped[snr] = {}
    if mod not in grouped[snr]:
        grouped[snr][mod] = {'rates': [], 'e0s': []}
    grouped[snr][mod]['rates'].append(rate)
    grouped[snr][mod]['e0s'].append(e0)

# compute width and height of the images in pixels
if(ptsSNR == 1):
    w = widXsize
else:
    w = widXsize/2

h = widYsize / ceil(ptsSNR/2)

# Plot for each SNR value
for snr, mod_data in grouped.items():
    plt.figure(figsize=(w*2.2/my_dpi, h*2.2/my_dpi), dpi=my_dpi)
    plt.title(f'SNR = {snr}', fontsize=8, color='white')  # Increase title font size
    for mod, mod_values in mod_data.items():
        plt.plot(mod_values['rates'], mod_values['e0s'], label=f'Mod {mod}', linewidth=1.5)  # Adjust line width
    plt.xlabel('Rate', fontsize=7, color='white')  # Increase x-axis label font size
    plt.ylabel('Error Exponent', fontsize=7, color='white')  # Increase y-axis label font size
    plt.xticks(fontsize=7, color='white')  # Increase x-axis tick font size
    plt.yticks(fontsize=7, color='white')  # Increase y-axis tick font size

    # Set legend properties
    legend = plt.legend(fontsize=5, facecolor='#3c3f41', edgecolor='white', framealpha=1)  # Set background dark and translucent, edge in white
    plt.setp(legend.get_frame(), linewidth=0.5)  # Set the edge thickness to be thinner
    plt.setp(legend.get_texts(), color='white')  # Set legend text color to white

    plt.grid(True)
    plt.tight_layout()  # Adjust subplot parameters to give specified padding
    plt.savefig(os.path.join(output_dir, f'plot_snr_{snr}.png'), dpi=my_dpi, transparent=True)  # Increase DPI for higher resolution

    plt.close()

plt.show()


if(save):
    for snr, mod_data in grouped.items():
        plt.figure(dpi=my_dpi)
        plt.title(f'SNR = {snr}', fontsize=8, color='black')  # Increase title font size
        for mod, mod_values in mod_data.items():
            plt.plot(mod_values['rates'], mod_values['e0s'], label=f'Mod {mod}', linewidth=1.5)  # Adjust line width
        plt.xlabel('Rate', fontsize=7, color='black')  # Increase x-axis label font size
        plt.ylabel('Error Exponent', fontsize=7, color='black')  # Increase y-axis label font size
        plt.xticks(fontsize=7, color='black')  # Increase x-axis tick font size
        plt.yticks(fontsize=7, color='black')  # Increase y-axis tick font size

        # Set legend properties
        legend = plt.legend(fontsize=5, facecolor='#3c3f41', edgecolor='black', framealpha=1)  # Set background dark and translucent, edge in black
        plt.setp(legend.get_frame(), linewidth=0.5)  # Set the edge thickness to be thinner
        plt.setp(legend.get_texts(), color='black')  # Set legend text color to black

        plt.grid(True)
        plt.tight_layout()  # Adjust subplot parameters to give specified padding
        plt.savefig(os.path.join(save_dir, f'plot_snr_{snr}.png'), dpi=my_dpi, transparent=True)  # Increase DPI for higher resolution

        plt.close()

    plt.show()
