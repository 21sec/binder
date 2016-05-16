/**@defgroup 属性模块
@{

@brief 设置,获取,存储系统及用户属性.主要用于自定义小数据的存储.

一个属性表示一个存在本地的可变的值,供应用及中间件设置或获取.
属性的值会存储在本地,以供下次开机时重新加载.
恢复出厂设置时这些值都会恢复为默认值.

@author lihui02@tcl.com

@version 1.0.0 2014/10/16 初稿
@version 1.0.1 2014/10/16 去掉对fpi错误码定义的依赖
@version 1.0.2 2014/10/16 增加Key的命名规范.
@version 1.0.3 2014/10/17 删除flush接口及相关的说明,小数据直接写入即可.增加get时内存管理的描述.
@version 1.0.4 2014/10/18 添加remove接口.
@version 1.0.5 2014/10/28 添加或者中间件配置信息专用Key规则.
*/

#ifndef __TOS_PROPERTY_H__
#define __TOS_PROPERTY_H__

#ifdef __cplusplus
extern "C" {
#endif

#define VALUE_TRUE      "true"
#define VALUE_FALSE     "false"
#define VALUE_ON    "on"
#define VALUE_OFF   "off"

/*
Load property to memory from flash, it should be called when tv start up
*/
//int sita_property_init(void); no one call in tvmanager native

/**
@brief 设置属性

将一个属性值设置到属性管理模块中,若key已存在则覆盖当前值.
对于Key的取值,请遵从以下规范:
- sita.$模块名.$Key名称              中间件保留前缀,所有中间件定义的Key须遵从此命名规范.如"sita.atv.pic.mode"
- ro.sita.$配置文件名.$域名.$字段名    获取中间件配置信息专用Key,用于获取只读的,中间件及平台的配置信息.各字段的意义分别为:
    -# 配置文件名(common) 通用配置信息,对应$F1_CONFIG环境变量指定的配置文件中的内容
    -# 配置文件名(model) 与当前模组相关的配置信息,对应Model ini配置文件中的内容
    -# 域名   配置项类型,对应配置文件中的域名,即ini文件中[]中的部分
    -# 字段名  配置项,对应配置文件中的Key
    -# 举例: ro.sita.model.PROJECT_NAME_CFG.PROJECT_NAME可获取当前模组(屏)的名称.详细的配置文件信息请参见<SITA配置项.xlsx>
    -# 注意: 此类Key需要在中间件实现时,自行读取中间件的配置文件.应用无需关注其过程,直接读取即可.
- app.$应用名称.$Key名称             应用保留前缀,所有应用定义的Key须遵从此命名规范.如"app.ipepg.switch"
- persist.$模块名.$Key 永久保持数据，即对应的Key设置后恢复出厂设置不会被清除。需配合sita,app等二级前缀使用，如:
    -# persist.sita.$模块名.$Key 中间件保留的永久保持数据前缀
    -# persist.app.$模块名.$Key 应用保留的永久保持数据前缀
- memory.$模块名.$Key 临时在内存中保持数据，即对应的Key设置后，掉电重启会被清除。需配合sita,app等二级前缀使用，如:
    -# memory.sita.$模块名.$Key 中间件保留的临时保持数据前缀
    -# memory.app.$模块名.$Key 应用保留的临时保持数据前缀
- 其它                              暂时保留,所有模块均不得使用.

@param[in] key 全局唯一属性关键字.
@param[in] value 属性的值.
@return 成功返回0;失败返回<0的错误代码
*/
int tos_property_set(const char *key,const char *value);

/**
@brief 获取属性

从属性管理模块中获取某个属性,若key不存在,则返回defValue.
本接口不会改变任何属性的状态,即key不存在时,defValue不会存储.

@note 若Key存在,返回值的内存由本模块管理,应用不能释放(free).若Key不存在,则直接返回defValue指针,其生命周期与defValue相同.
@note 建议模块用hash表实现key-value的存储及管理,以减少内存的申请释放及碎片化.

@param[in] key 全局唯一属性关键字.
@param[in] defValue 默认的属性的值,若key不存在则直接返回该值.
@return 成功返回属性的值,否则返回defValue.
*/
const char * tos_property_get(const char *key,const char *defValue);

/**
@brief 删除指定属性

删除后,Key对应的属性为不存在状态.
删除一个不存在的Key会返回失败.
@return 成功返回0;失败返回<0的错误代码.
*/
int tos_property_remove(const char *key);

/**
@brief 删除所有的属性值

用于恢复出厂设置等场景.
@return 成功返回0;失败返回<0的错误代码.
*/
int tos_property_reset(void);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
