
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)                   (REG |=(1<<BIT))

#define CLR_BIT(REG,BIT)                  ( REG &=(~(1<<BIT)))

#define TOG_BIT(REG,BIT)                  ( REG ^=(1<<BIT))

#define GET_BIT(REG,BIT)                  ((REG>>BIT)&0x01)

#define SET_PORT(REG)                     (REG =0xff)
#define CLR_PORT(REG)                     (REG =0x00)
#define SET_PORT_WITH_VALUE(REG,VALUE)    (REG = VALUE)
#define GET_PORT(REG)                     (REG & 0xff)


#endif /* BIT_MATH_H_ */


