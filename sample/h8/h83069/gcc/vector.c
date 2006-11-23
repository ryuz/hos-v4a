#include "kernel.h"

extern void _reset_handler(void);
extern void _kernel_vector_dmy(void);
extern void _kernel_vector_024(void);

const FP vectors[] __attribute__ ((section (".vectors"))) =
{
	_reset_handler,			/* ベクタ0   リセット */
	_kernel_vector_dmy,		/* ベクタ1 */
	_kernel_vector_dmy,		/* ベクタ2 */
	_kernel_vector_dmy,		/* ベクタ3 */
	_kernel_vector_dmy,		/* ベクタ4 */
	_kernel_vector_dmy,		/* ベクタ5 */
	_kernel_vector_dmy,		/* ベクタ6 */
	_kernel_vector_dmy,		/* ベクタ7   NMI */
	_kernel_vector_dmy,		/* ベクタ8   TRAP0 */
	_kernel_vector_dmy,		/* ベクタ9   TRAP1 */
	_kernel_vector_dmy,		/* ベクタ10  TRAP2 */
	_kernel_vector_dmy,		/* ベクタ11  TRAP3 */
	_kernel_vector_dmy,		/* ベクタ12  IRQ0 */
	_kernel_vector_dmy,		/* ベクタ13 */
	_kernel_vector_dmy,		/* ベクタ14 */
	_kernel_vector_dmy,		/* ベクタ15 */
	_kernel_vector_dmy,		/* ベクタ16 */
	_kernel_vector_dmy,		/* ベクタ17 */
	_kernel_vector_dmy,		/* ベクタ18 */
	_kernel_vector_dmy,		/* ベクタ19 */
	_kernel_vector_dmy,		/* ベクタ20 */
	_kernel_vector_dmy,		/* ベクタ21 */
	_kernel_vector_dmy,		/* ベクタ22 */
	_kernel_vector_dmy,		/* ベクタ23 */
	_kernel_vector_024,		/* ベクタ24 */
	_kernel_vector_dmy,		/* ベクタ25 */
	_kernel_vector_dmy,		/* ベクタ26 */
	_kernel_vector_dmy,		/* ベクタ27 */
	_kernel_vector_dmy,		/* ベクタ28 */
	_kernel_vector_dmy,		/* ベクタ29 */
	_kernel_vector_dmy,		/* ベクタ30 */
	_kernel_vector_dmy,		/* ベクタ31 */
	_kernel_vector_dmy,		/* ベクタ32 */
	_kernel_vector_dmy,		/* ベクタ33 */
	_kernel_vector_dmy,		/* ベクタ34 */
	_kernel_vector_dmy,		/* ベクタ35 */
	_kernel_vector_dmy,		/* ベクタ36 */
	_kernel_vector_dmy,		/* ベクタ37 */
	_kernel_vector_dmy,		/* ベクタ38 */
	_kernel_vector_dmy,		/* ベクタ39 */
	_kernel_vector_dmy,		/* ベクタ40 */
	_kernel_vector_dmy,		/* ベクタ41 */
	_kernel_vector_dmy,		/* ベクタ42 */
	_kernel_vector_dmy,		/* ベクタ43 */
	_kernel_vector_dmy,		/* ベクタ44 */
	_kernel_vector_dmy,		/* ベクタ45 */
	_kernel_vector_dmy,		/* ベクタ46 */
	_kernel_vector_dmy,		/* ベクタ47 */
	_kernel_vector_dmy,		/* ベクタ48 */
	_kernel_vector_dmy,		/* ベクタ49 */
	_kernel_vector_dmy,		/* ベクタ50 */
	_kernel_vector_dmy,		/* ベクタ51 */
	_kernel_vector_dmy,		/* ベクタ52 */
	_kernel_vector_dmy,		/* ベクタ53 */
	_kernel_vector_dmy,		/* ベクタ54 */
	_kernel_vector_dmy,		/* ベクタ55 */
	_kernel_vector_dmy,		/* ベクタ56 */
	_kernel_vector_dmy,		/* ベクタ57 */
	_kernel_vector_dmy,		/* ベクタ58 */
	_kernel_vector_dmy,		/* ベクタ59 */
	_kernel_vector_dmy,		/* ベクタ60 */
	_kernel_vector_dmy,		/* ベクタ61 */
	_kernel_vector_dmy,		/* ベクタ62 */
	_kernel_vector_dmy,		/* ベクタ63 */
};


