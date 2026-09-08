// Test: align_func_proto_span_num_mixed - macro calls on parameters.

VeryLongGlobalType global_func_one(int _CALL_A_MACRO(param1),
                                   double param2,
                                   // A comment
                                   float param3
                                  );
