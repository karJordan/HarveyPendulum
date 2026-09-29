#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////

// Initialise Fuzzy Rules

void initFuzzyRules(fuzzy_system_rec *fl)
{

   const int
       no_of_x_rules = 25,
       no_of_theta_rules = 25;

   int i;

   //----------------------------------------------------------------------------
   // Every Yamakawa rule uses the combined inputs X and Y
   for (i = 0; i < fl->no_of_rules; i++)
   {
      fl->rules[i].inp_index[0] = INPUT_X;
      fl->rules[i].inp_index[1] = INPUT_Y;
   }

   // Y = PM
   // Rule 0: IF X is NM AND Y is PM THEN output is NS
   fl->rules[0].inp_fuzzy_set[0] = in_nm;
   fl->rules[0].inp_fuzzy_set[1] = in_pm;
   fl->rules[0].out_fuzzy_set = out_ns;

   // Rule 1: IF X is ZE AND Y is PM THEN output is PS
   fl->rules[1].inp_fuzzy_set[0] = in_ze;
   fl->rules[1].inp_fuzzy_set[1] = in_pm;
   fl->rules[1].out_fuzzy_set = out_ps;

   // Rule 2: IF X is PM AND Y is PM THEN output is PL
   fl->rules[2].inp_fuzzy_set[0] = in_pm;
   fl->rules[2].inp_fuzzy_set[1] = in_pm;
   fl->rules[2].out_fuzzy_set = out_pl;

   // Y = PS
   // Rule 3: IF X is NS AND Y is PS THEN output is NS
   fl->rules[3].inp_fuzzy_set[0] = in_ns;
   fl->rules[3].inp_fuzzy_set[1] = in_ps;
   fl->rules[3].out_fuzzy_set = out_ns;

   // Rule 4: IF X is PS AND Y is PS THEN output is PM
   fl->rules[4].inp_fuzzy_set[0] = in_ps;
   fl->rules[4].inp_fuzzy_set[1] = in_ps;
   fl->rules[4].out_fuzzy_set = out_pm;

   // Y = ZE
   // Rule 5: IF X is NM AND Y is ZE THEN output is NM
   fl->rules[5].inp_fuzzy_set[0] = in_nm;
   fl->rules[5].inp_fuzzy_set[1] = in_ze;
   fl->rules[5].out_fuzzy_set = out_nm;

   // Rule 6: IF X is ZE AND Y is ZE THEN output is ZE
   fl->rules[6].inp_fuzzy_set[0] = in_ze;
   fl->rules[6].inp_fuzzy_set[1] = in_ze;
   fl->rules[6].out_fuzzy_set = out_ze;

   // Rule 7: IF X is PM AND Y is ZE THEN output is PM
   fl->rules[7].inp_fuzzy_set[0] = in_pm;
   fl->rules[7].inp_fuzzy_set[1] = in_ze;
   fl->rules[7].out_fuzzy_set = out_pm;

   // Y = NS
   // Rule 8: IF X is NS AND Y is NS THEN output is NM
   fl->rules[8].inp_fuzzy_set[0] = in_ns;
   fl->rules[8].inp_fuzzy_set[1] = in_ns;
   fl->rules[8].out_fuzzy_set = out_nm;

   // Rule 9: IF X is PS AND Y is NS THEN output is PS
   fl->rules[9].inp_fuzzy_set[0] = in_ps;
   fl->rules[9].inp_fuzzy_set[1] = in_ns;
   fl->rules[9].out_fuzzy_set = out_ps;

   // Y = NM
   // Rule 10: IF X is NM AND Y is NM THEN output is NL
   fl->rules[10].inp_fuzzy_set[0] = in_nm;
   fl->rules[10].inp_fuzzy_set[1] = in_nm;
   fl->rules[10].out_fuzzy_set = out_nl;

   // Rule 11: IF X is ZE AND Y is NM THEN output is NS
   fl->rules[11].inp_fuzzy_set[0] = in_ze;
   fl->rules[11].inp_fuzzy_set[1] = in_nm;
   fl->rules[11].out_fuzzy_set = out_ns;

   // Rule 12: IF X is PM AND Y is NM THEN output is PS
   fl->rules[12].inp_fuzzy_set[0] = in_pm;
   fl->rules[12].inp_fuzzy_set[1] = in_nm;
   fl->rules[12].out_fuzzy_set = out_ps;

   /*
   //----------------------------------------------------------------------------
   //THETA vs. THETA_DOT
   //
      for (i = 0;i < no_of_theta_rules;i++) {
          fl->rules[i].inp_index[0] = in_theta;
          fl->rules[i].inp_index[1] = in_theta_dot;
      }

      // Regions for theta and theta_dot:
      //sample only
      // fl->rules[0].inp_fuzzy_set[0] = in_nl;
      // fl->rules[0].inp_fuzzy_set[1] = in_nl;



   //----------------------------------------------------------------------------
   //X vs. X_DOT
   //
      for (i = 0;i < no_of_x_rules;i++) {
           fl->rules[i + no_of_theta_rules].inp_index[0] = in_x;
           fl->rules[i + no_of_theta_rules].inp_index[1] = in_x_dot;
      }

      //Regions for x and x_dot:
      //sample only
      // fl->rules[25+0].inp_fuzzy_set[0] = in_nl;
      // fl->rules[25+0].inp_fuzzy_set[1] = in_nl;

      //and so on, and so forth...

      // fl->rules[25+24].out_fuzzy_set = out_nl;
   */

   return;
}

void initMembershipFunctions(fuzzy_system_rec *fl)
{

   /* The X membership functions */

   // Sample routines only, to give you an idea of what to do here
   //~ fl->inp_mem_fns[in_x][in_neg] = init_trapz (-1.5,-0.5,0,0,left_trapezoid);
   //~ fl->inp_mem_fns[in_x][in_ze] = init_trapz (-1.5,-0.5,0.5,1.5,regular_trapezoid);
   //~ fl->inp_mem_fns[in_x][in_pos] = init_trapz (0.5,1.5,0,0,right_trapezoid);

   /* The X dot membership functions */
   // enter the appropriate membership function initialisations here

   /* The theta membership functions */
   // enter the appropriate membership function initialisations here

   /* The theta dot membership functions */
   // enter the appropriate membership function initialisations here

   return;
}

void initFuzzySystem(fuzzy_system_rec *fl)
{

   // Note: The settings of these parameters will depend upon your fuzzy system design
   fl->no_of_inputs = 2; /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 13; // 13 rules based on Yamakawa
   fl->no_of_inp_regions = 5;
   fl->no_of_outputs = 9;

   coefficient_A = 1.0;
   coefficient_B = 1.0;
   coefficient_C = 1.0;
   coefficient_D = 1.0;

   // output values will go here

   // Sample only
   //  fl->output_values [out_nvl]=-95.0;
   //  fl->output_values [out_nl] = -85.0;

   fl->rules = (rule *)malloc((size_t)(fl->no_of_rules * sizeof(rule)));
   initFuzzyRules(fl);
   initMembershipFunctions(fl);
   return;
}

//////////////////////////////////////////////////////////////////////////////

trapezoid init_trapz(float x1, float x2, float x3, float x4, trapz_type typ)
{

   trapezoid trz;
   trz.a = x1;
   trz.b = x2;
   trz.c = x3;
   trz.d = x4;
   trz.tp = typ;
   switch (trz.tp)
   {

   case regular_trapezoid:
      trz.l_slope = 1.0 / (trz.b - trz.a);
      trz.r_slope = 1.0 / (trz.c - trz.d);
      break;

   case left_trapezoid:
      trz.r_slope = 1.0 / (trz.a - trz.b);
      trz.l_slope = 0.0;
      break;

   case right_trapezoid:
      trz.l_slope = 1.0 / (trz.b - trz.a);
      trz.r_slope = 0.0;
      break;
   } /* end switch  */

   return trz;
} /* end function */

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
float trapz(float x, trapezoid trz)
{
   switch (trz.tp)
   {

   case left_trapezoid:
      if (x <= trz.a)
         return 1.0;
      if (x >= trz.b)
         return 0.0;
      /* a < x < b */
      return trz.r_slope * (x - trz.b);

   case right_trapezoid:
      if (x <= trz.a)
         return 0.0;
      if (x >= trz.b)
         return 1.0;
      /* a < x < b */
      return trz.l_slope * (x - trz.a);

   case regular_trapezoid:
      if ((x <= trz.a) || (x >= trz.d))
         return 0.0;
      if ((x >= trz.b) && (x <= trz.c))
         return 1.0;
      if ((x >= trz.a) && (x <= trz.b))
         return trz.l_slope * (x - trz.a);
      if ((x >= trz.c) && (x <= trz.d))
         return trz.r_slope * (x - trz.d);

   } /* End switch  */

   return 0.0; /* should not get to this point */
} /* End function */

//////////////////////////////////////////////////////////////////////////////
float min_of(float values[], int no_of_inps)
{
   int i;
   float val;
   val = values[0];
   for (i = 1; i < no_of_inps; i++)
   {
      if (values[i] < val)
         val = values[i];
   }
   return val;
}

//////////////////////////////////////////////////////////////////////////////
float fuzzy_system(float inputs[], fuzzy_system_rec fz)
{
   int i, j;
   short variable_index, fuzzy_set;
   float sum1 = 0.0, sum2 = 0.0, weight;
   float m_values[MAX_NO_OF_INPUTS];

   for (i = 0; i < fz.no_of_rules; i++)
   {
      for (j = 0; j < fz.no_of_inputs; j++)
      {
         variable_index = fz.rules[i].inp_index[j];
         fuzzy_set = fz.rules[i].inp_fuzzy_set[j];
         m_values[j] = trapz(inputs[variable_index],
                             fz.inp_mem_fns[variable_index][fuzzy_set]);
      } /* end j  */

      weight = min_of(m_values, fz.no_of_inputs);

      sum1 += weight * fz.output_values[fz.rules[i].out_fuzzy_set];
      sum2 += weight;
   } /* end i  */

   if (fabs(sum2) < TOO_SMALL)
   {
      cout << "\r\nFLPRCS Error: Sum2 in fuzzy_system is 0.  Press key: " << endl;
      //~ getch();
      //~ exit(1);
      return 0.0;
   }

   return (sum1 / sum2);
} /* end fuzzy_system  */

//////////////////////////////////////////////////////////////////////////////
void free_fuzzy_rules(fuzzy_system_rec *fz)
{
   if (fz->allocated)
   {
      free(fz->rules);
   }

   fz->allocated = false;
   return;
}
