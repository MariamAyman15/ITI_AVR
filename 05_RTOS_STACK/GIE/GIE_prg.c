#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "GIE_cfg.h"
#include "GIE_int.h"
#include "GIE_prv.h"

//ENABLE GIE
void GIE_voidEnableGlobalInterrupt(void)
{
	SET_BIT(MSREG_REG,7);
}

//DISABLE GIE
void GIE_voidDisableGlobalInterrupt(void)
{
	CLR_BIT(MSREG_REG,7);

}
