#include "main.h"
/**
* in_params - clears struct fields and reset buf
* @par: the parameters struct
* @ap: the argument pointer
* Return: void
*/
void in_params(par_t *par, va_list ap)
{
	par->unsign = 0;
	par->plus_flag = 0;
	par->space_flag = 0;
	par->hashtag_flag = 0;
	par->zero_flag = 0;
	par->minus_flag = 0;
	par->width = 0;
	par->precision = UINT_MAX;
	par->high_modifier = 0;
	par->low_modifier = 0;
	(void) ap;
}
