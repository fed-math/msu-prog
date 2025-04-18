
typedef double (*dtod) (double);

int iseq(double x, double y);

int fac (int n);

double derivative (double x0, dtod f);

int newton_root(double* x, double a, double b, dtod f, double epsilon);

double simpson_formula(double a, double b, dtod f);

int simpson_check(double x, double v, int N);

double simpson_integral(double a, double b, dtod f, double epsilon);

int bisection_minimization(double* x, double a, double b, dtod f, double epsilon);

double quadratic_spline(double a, double b, dtod f);

double cos_approx(double x, double epsilon);