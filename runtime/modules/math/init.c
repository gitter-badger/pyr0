/*
 * File: init.c
 * Author: Fabien Siron <fabien.siron@epita.fr>
 */

#include <tinypy/tp.h>
#include <tinypy/dict.h>
#include <tinypy/string.h>
#include <tinypy/misc.h>

#ifndef M_E
#define M_E     2.7182818284590452354
#endif
#ifndef M_PI
#define M_PI    3.14159265358979323846
#endif

static char *help =
	"Math routines of pyr0, equivalent of math module in cpython.\n"
	"\n"
	"This exports:\n"
	"\t* math.pi is the pi constant\n"
	"\t* math.e is the euler number constant\n";

void math_init(TP)
{
	/* module */
	tp_obj math_mod = tp_dict(tp);

	/* methods */
  
	/* 
	 * XXX: okay both method cannot be printed because linux kernel vsprintf
	 * does not support floating point numbers.
	 */
	tp_set(tp, math_mod, tp_string("pi"), tp_number(M_PI));
	tp_set(tp, math_mod, tp_string("e"), tp_number(M_E));

	/* special attributes */
	tp_set(tp, math_mod, tp_string("__doc__"),
	       tp_string(help));
	tp_set(tp, math_mod, tp_string("__name__"), tp_string("math"));
	tp_set(tp, math_mod, tp_string("__file__"), tp_string(__FILE__));

	/* bind */
	tp_set(tp, tp->modules, tp_string("math"), math_mod);
}
