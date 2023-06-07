#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#define DEFAULT_DIGITS 60

#define DIGITS_PER_ITERATION 14.1816474627254776555

char *chudnovsky(unsigned long digits)
{
	mpf_t result, con, A, B, F, sum;
	mpz_t a, b, c, d, e;
	char *output;
	mp_exp_t exp;
	double bits_per_digit;

	unsigned long int k, threek;
	unsigned long iterations = (digits/DIGITS_PER_ITERATION)+1;
	unsigned long precision_bits;
:
	bits_per_digit = 3.32192809488736234789; 
	precision_bits = (digits * bits_per_digit) + 1;

	mpf_set_default_prec(precision_bits);

	mpf_inits(result, con, A, B, F, sum, NULL);
	mpz_inits(a, b, c, d, e, NULL);

	mpf_set_ui(sum, 0); 


	mpf_sqrt_ui(con, 10005);
	mpf_mul_ui(con, con, 426880);

	for (k = 0; k < iterations; k++) {
		threek = 3*k;

		mpz_fac_ui(a, 6*k);  

		mpz_set_ui(b, 545140134); 
		mpz_mul_ui(b, b, k);
		mpz_add_ui(b, b, 13591409);

		mpz_fac_ui(c, threek);  

		mpz_fac_ui(d, k);  
		mpz_pow_ui(d, d, 3);

		mpz_ui_pow_ui(e, 640320, threek); 
		if ((threek&1) == 1) { mpz_neg(e, e); }

		mpz_mul(a, a, b);
		mpf_set_z(A, a);

		mpz_mul(c, c, d);
		mpz_mul(c, c, e);
		mpf_set_z(B, c);

		mpf_div(F, A, B);

		mpf_add(sum, sum, F);
	}

	mpf_ui_div(sum, 1, sum); 
	mpf_mul(sum, sum, con); 

	output = mpf_get_str(NULL, &exp, 10, digits, sum); 

	mpf_clears(result, con, A, B, F, sum, NULL);
	mpz_clears(a, b, c, d, e, NULL);

	return output;
}
void usage_exit(void)
{
	fprintf(stderr, "usage: chudnovsky [digits]\n");
	exit(1);
}
int main(int argc, char **argv)
{
	char *pi, *endptr;
	long digits;

	switch (argc) {
		case 1:
			digits = DEFAULT_DIGITS;
			break;

		case 2:
			digits = strtol(argv[1], &endptr, 10);
			if (*endptr != '\0') { usage_exit(); }
			break;

		default:
			usage_exit();
	}

	if (digits < 1) { usage_exit(); }

	pi = chudnovsky(digits);

	printf("%.1s.%s\n", pi, pi+1);

	free(pi);

	return 0;
}
