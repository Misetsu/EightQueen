#include "EightQueen.h"
#include "DxLib.h"
#include <stdio.h>

extern int Solution[100][9];

int eightqueen(int Queens) {
	int i, j, k, flag, not_finish = 1, count = 0;
	int a[9];

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 9; j++) {
			Solution[i][j] = 0;
		}
	}

	i = 1;
	a[1] = 1;

	if (Queens > 1) {
		while (not_finish) {
			while (not_finish && i <= Queens) {

				for (flag = 1, k = 1; flag && k < i; k++) {
					if (a[k] == a[i]) {
						flag = 0;
					}
				}

				for (k = 1; flag && k < i; k++) {
					if ((a[i] == a[k] - (k - i)) || (a[i] == a[k] + (k - i))) {
						flag = 0;
					}
				}

				if (flag == 0) {

					if (a[i] == a[i - 1]) {
						
						i--;

						if (i > 1 && a[i] == Queens) {
							a[i] = 1;
						} else if (i == 1 && a[i] == Queens) {
							not_finish = 0;
						} else {
							a[i]++;
						}

					} else if (a[i] == Queens) {
						a[i] = 1;
					} else {
						a[i]++;
					}

				} else if (++i <= Queens) {

					if (a[i - 1] == Queens) {
						a[i] = 1;
					} else {
						a[i] = a[i - 1] + 1;
					}

				}
			}

			if (not_finish) {

				for (j = 0; j <= Queens; j++) {
					Solution[count][j] = a[j];
				}

				++count;

				if (a[Queens - 1] < Queens) {
					a[Queens - 1]++;
				} else {
					a[Queens - 1] = 1;
				}

				i = Queens - 1;

			}
		}
	} else {
		count = 1;
		Solution[0][1] = 1;
	}

	return count;
}