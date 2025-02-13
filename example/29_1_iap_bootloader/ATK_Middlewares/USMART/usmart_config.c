#include "usmart.h"
#include "usmart_str.h"

/******************************************************************************************/
/* user configuration area
 * This should include the header file declared by the function used (user added)
 */

#include "../../BSP/STMFLASH/stmflash.h"


/* Function name list initialization (user added)
 * Here the user enters directly the name of the function to be executed and its lookup string
 */
struct _m_usmart_nametab usmart_nametab[] =
{
#if USMART_USE_WRFUNS == 1      /* If read and write operations are enabled */
    (void *)read_addr, "uint32_t read_addr(uint32_t addr)",
    (void *)write_addr, "void write_addr(uint32_t addr,uint32_t val)",
#endif

	{(void *)stmflash_read_word, "uint32_t stmflash_read_word(uint32_t addr)",},
    {(void *)test_write, "void test_write(uint32_t waddr, uint16_t wdata)"},

};

/******************************************************************************************/

/* The function controls the manager initialization
 * Get the names of each controlled function
 * Get the total number of functions
 */
struct _m_usmart_dev usmart_dev =
{
    usmart_nametab,
    usmart_init,
    usmart_cmd_rec,
    usmart_exe,
    usmart_scan,
    sizeof(usmart_nametab) / sizeof(struct _m_usmart_nametab), /* Function quantity */
    0,      /* Arity */
    0,      /* Function ID */
    1,      /* Parameter display type,0, decimal; 1, hexadecimal */
    0,      /* Parameter type.bitx:0, digit; 1, string */
    0,      /* The length temporary table for each parameter requires MAX PARM initialization*/
    0,      /* The parameter of the function requires PARM LEN initialization */
};



















