import matplotlib.pyplot as plt
import pandas as pd
import os
import sys

# Load the data
data = pd.read_csv('data.csv')

# Ensure the output directory exists
output_dir = 'plots'
os.makedirs(output_dir, exist_ok=True)

# Get the unique SNR values
unique_snr = data['SNR'].unique()

for snr in unique_snr:
    subset = data[data['SNR'] == snr]

    plt.figure()
    for rate in subset['Rate'].unique():
        rate_subset = subset[subset['Rate'] == rate]
        for mod in rate_subset['Mod'].unique():
            mod_subset = rate_subset[rate_subset['Mod'] == mod]
            plt.plot(mod_subset['Mod'], mod_subset['e0'], label=f'Rate: {rate}, Mod: {mod}')

    plt.title(f'SNR: {snr}')
    plt.xlabel('Modulation')
    plt.ylabel('e0')
    plt.legend()
    plt.savefig(os.path.join(output_dir, f'plot_snr_{snr}.png'))
    plt.close()
