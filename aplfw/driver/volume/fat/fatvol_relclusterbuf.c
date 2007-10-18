
#include <stddef.h>
#include "fatvol_local.h"


/**< クラスタ読み込み */
int FatVol_RelClusterBuf(
		C_FATVOL    *self,
		void        *pBuf,
		int         iDirty)
{
	T_FATVOL_CLUSTERBUF	*pClusterBuf;
	
	/* バッファ情報取得 */
	pClusterBuf = (T_FATVOL_CLUSTERBUF *)((char *)pBuf - sizeof(T_FATVOL_CLUSTERBUF));
	
	if ( iDirty )
	{
		pClusterBuf->iDirty = iDirty;
	}
	
	return FATVOL_ERR_OK;	
}


/* end of file */
