/*
 * LTLf formula
 * created by Jianwen Li at May 29th, 2014
 */
 
#ifndef LTLF_H
#define	LTLF_H

#include "util/define.h"
#include "util/hash_map.h"
#include "util/hash_set.h"
#include "ltlparser/ltl_formula.h"

class ltlf_formula
{
private:
  int _op;
  ltlf_formula* _left;
  ltlf_formula* _right;
  size_t _hash;
  aalta_formula *_unique; // ָ��Ψһָ���ʶ
  aalta_formula *_simp; // ָ�򻯼��Ĺ�ʽָ��
  
public:
  struct ff_hash
  {

    size_t operator () (const ltlf_formula& ff) const
    {
      return ff._hash;
    }
  };

  /* afָ���hash���� */
  struct ff_prt_hash
  {

    size_t operator () (const ltlf_formula *ff_prt) const
    {
      return size_t (ff_prt);
    }
  };

  /* afָ���hash���� */
  struct ff_prt_hash2
  {

    size_t operator () (const ltlf_formula *ff_prt) const
    {
      return ff_prt->_hash;
    }
  };
  /* afָ�����Ⱥ��� */
  struct ff_prt_eq
  {

    bool operator () (const ltlf_formula *ff_prt1, const ltlf_formula *ff_prt2) const
    {
      return *ff_prt1 == *ff_prt2;
    }
  };
  
  
};
