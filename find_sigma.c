void findDataPeaks(int size, double* ratio, double* peaks, int* peak_locations, double* peak_widths, double* peak_prominence, int* peakCounts) {
   

        left_prominence_check = ratio[0];

        for (i = 1; i < size-1; i++) {  // both left and right ends are ommitted.
            if (vDerivatives[i] >= 0 && vDerivatives[i] > vDerivatives[i-1]) { // Point i is a local max
               if (vDerivatives[i] > 0) {
                        newest_peak = ratio[i];
                        peaks[p] = newest_peak;
                        peak_locations[p] = i;
                        if (!passed_local_max) {
                                left_prominence_location = i;
                        }
                        passed_local_max = true;
                }
            } else if (vDerivatives[i] <= 0 && vDerivatives[i] < vDerivatives[i - 1]) { //Point i is a local min
                increment = false;
                while (i < size && vDerivatives[i] < 0) {
                    i++;
                    increment = true;
                }
                if (increment) {
                        i--; // Go back to the last minima point.
                }
                if (passed_local_max) {
                    *peakCounts = p+1;
                    printf("detected maxima point Data(dvt)[%d] ==> %0.4f PeakCounts: %d i:%d\n", peak_locations[p], peaks[p], *peakCounts, i-1);
                    right_prominence_check = ratio[i];
                    peak_prominence[p] = fmin(newest_peak - left_prominence_check, newest_peak - right_prominence_check);
                    sigma = (peaks[p] - ratio[i])/4;
                    printf("max: %0.4f min: %0.4f sigma: %0.4f\n", peaks[p], ratio[i], sigma);
                    peak_widths[p] = 2.355 * sigma;
                    left_prominence_check = right_prominence_check;
                    passed_local_max = false;
                    p++;
                } else {
                    left_prominence_check = ratio[i];
                }
                left_prominence_location = i;
            }
        }
}
