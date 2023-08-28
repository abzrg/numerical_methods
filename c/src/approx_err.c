#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>


#define TOLERANCE 1e-6

#define MAX_ITER 31

#define ARR_LEN(ARR) sizeof((ARR)) / sizeof((ARR)[0])


/**
 * A specific function whose derivative will be calculated
 */
double func(double x)
{
    return 2 * exp(0.5 * x);
}

/**
 * Calculates the approximate derivative of a function using forward euler
 * method
 *
 * Returns: true if h is not zero (considering a certain tolerance)
 *
 * @param f: function whose derivative we are trying to calculate
 * @param x: the position of the function
 * @param h: step size
 * @param result: the value of the function derivative will be populated in this
 * address
 */
bool forward_euler(double (*f)(double), double x, double h, double* result)
{
    // Check if h is not "zero" with respect to a TOLERANCE
    if (h < TOLERANCE) {
        return false;
    }

    assert(result != NULL);
    *result = (f(x + h) - f(x)) / h;

    return true;
}

/**
 * Given current and previous iteration/approximation value returns the relative
 * error (does not return percentage)
 */
double relative_error(double curr_approx, double prev_approx)
{
    double rel_err = (curr_approx - prev_approx) / curr_approx;
    return rel_err > 0 ? rel_err : (-1 * rel_err);
}

//----<main>--------------------------------------------------------------------

int main(void)
{
    double x = 3;

    // Populating step size
    double steps[MAX_ITER] = { 0 };
    for (size_t i = 0; i < MAX_ITER; i++) {
        steps[i] = 8.0 / pow(2.0, (double)i);
    }

    // Initialize current and previous approximation
    double curr_approx = 0.0;
    double prev_approx = 0.0;

    // Printe the header row
    printf("i\th\t\tDeriv.\t\tRelErr.\n");
    printf("------------------------------------------------\n");

    // Print a table of h, derivative, and relative error
    for (size_t i = 0; i < ARR_LEN(steps); i++) {
        // If h was too small or zero then do nothing
        if (!forward_euler(func, x, steps[i], &curr_approx)) {
            fprintf(stderr, "The step was almost zero. Either change the step"
                            " size (h) to a non-zero value or decrease the"
                            " tolerance\n");
            break;
        }

        // Get the relaive error
        double rel_err = relative_error(curr_approx, prev_approx);

        // Print the row
        printf("%zu\t%lf\t%lf\t%lf\n", i, steps[i], curr_approx, rel_err);

        // Update the prvious error for the next iteration
        prev_approx = curr_approx;
    }

    return 0;
}
