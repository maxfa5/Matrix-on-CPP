#include "test.h"

TEST(TestInverse, TestInverseException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException2) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException3) {
  S21Matrix test_matrix(1, 5);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException4) {
  S21Matrix test_matrix(5, 1);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException5) {
  S21Matrix test_matrix(5, 4);
  FillMatrix(test_matrix, 5.5);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на определитель, равный 0
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestInverse, TestInverseZero1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_rows(), 1);

  matrix1(0, 0) = 0.0;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero2) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 12;
  matrix1(0, 2) = 0.0;
  matrix1(1, 0) = 14;
  matrix1(1, 1) = 1.5;
  matrix1(1, 2) = 0.0;
  matrix1(2, 0) = 1.7;
  matrix1(2, 1) = 18;
  matrix1(2, 2) = 0.0;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero3) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(1, 0) = 1.4;
  matrix1(1, 1) = 1.5;
  matrix1(1, 2) = 1.6;
  matrix1(2, 0) = 1.7;
  matrix1(2, 1) = 1.8;
  matrix1(2, 2) = 1.9;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero4) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = -66;
  matrix1(0, 1) = -66;
  matrix1(0, 2) = -66;
  matrix1(1, 0) = -66;
  matrix1(1, 1) = -66;
  matrix1(1, 2) = -66;
  matrix1(2, 0) = -66;
  matrix1(2, 1) = -66;
  matrix1(2, 2) = -66;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero5) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 9.05718;
  matrix1(0, 1) = 9.05718;
  matrix1(0, 2) = 9.05718;

  matrix1(1, 0) = 9.05718;
  matrix1(1, 1) = 9.05718;
  matrix1(1, 2) = 9.05718;

  matrix1(2, 0) = -9.0963;
  matrix1(2, 1) = -9.72731;
  matrix1(2, 2) = 1.16551;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero6) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 561.395;
  matrix1(0, 1) = 370.469;
  matrix1(0, 2) = 441.733;
  matrix1(0, 3) = -952.484;
  matrix1(0, 4) = -506.042;

  matrix1(1, 0) = 356.219;
  matrix1(1, 1) = 356.219;
  matrix1(1, 2) = 356.219;
  matrix1(1, 3) = 356.219;
  matrix1(1, 4) = 356.219;

  matrix1(2, 0) = 113.190;
  matrix1(2, 1) = 919.346;
  matrix1(2, 2) = -629.533;
  matrix1(2, 3) = 577.491;
  matrix1(2, 4) = -770.006;

  matrix1(3, 0) = 356.219;
  matrix1(3, 1) = 356.219;
  matrix1(3, 2) = 356.219;
  matrix1(3, 3) = 356.219;
  matrix1(3, 4) = 356.219;

  matrix1(4, 0) = 964.659;
  matrix1(4, 1) = 370.425;
  matrix1(4, 2) = -226.376;
  matrix1(4, 3) = 907.791;
  matrix1(4, 4) = 679.804;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero7) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 356.219;
  matrix1(0, 1) = 356.219;
  matrix1(0, 2) = 356.219;
  matrix1(0, 3) = 356.219;
  matrix1(0, 4) = 356.219;

  matrix1(1, 0) = 356.219;
  matrix1(1, 1) = 356.219;
  matrix1(1, 2) = 356.219;
  matrix1(1, 3) = 356.219;
  matrix1(1, 4) = 356.219;

  matrix1(2, 0) = 113.190;
  matrix1(2, 1) = 919.346;
  matrix1(2, 2) = -629.533;
  matrix1(2, 3) = 577.491;
  matrix1(2, 4) = -770.006;

  matrix1(3, 0) = 561.395;
  matrix1(3, 1) = 370.469;
  matrix1(3, 2) = 441.733;
  matrix1(3, 3) = -952.484;
  matrix1(3, 4) = -506.042;

  matrix1(4, 0) = 964.659;
  matrix1(4, 1) = 370.425;
  matrix1(4, 2) = -226.376;
  matrix1(4, 3) = 907.791;
  matrix1(4, 4) = 679.804;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на определитель, не равный 0
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestInverse, TestInverse1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_rows(), 1);

  matrix1(0, 0) = 1.5;

  matrix1.TestInverse(matrix1);
}

TEST(TestInverse, TestInverse2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(1, 0) = 1.3;
  matrix1(1, 1) = 1.4;

  matrix1.TestInverse(matrix1);
}

TEST(TestInverse, TestInverse3) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = -7.00037610391155;
  matrix1(1, 0) = -6.32839397341013;
  matrix1(2, 0) = 10.222164043691;
  matrix1(0, 1) = -9.82599597726949;
  matrix1(1, 1) = 3.03237457247451;
  matrix1(2, 1) = 0.587724786484614;
  matrix1(0, 2) = 8.27683520526625;
  matrix1(1, 2) = -4.28063526446931;
  matrix1(2, 2) = -6.93227237439714;

  matrix1.TestInverse(matrix1);
}

TEST(TestInverse, TestInverse4) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  matrix1(0, 0) = -7.00037610391155;
  matrix1(1, 0) = -6.32839397341013;
  matrix1(2, 0) = 10.222164043691;
  matrix1(3, 0) = 7.95983747509308;
  matrix1(0, 1) = -9.82599597726949;
  matrix1(1, 1) = 3.03237457247451;
  matrix1(2, 1) = 0.587724786484614;
  matrix1(3, 1) = -3.41600720770657;
  matrix1(0, 2) = 8.27683520526625;
  matrix1(1, 2) = -4.28063526446931;
  matrix1(2, 2) = -6.93227237439714;
  matrix1(3, 2) = -10.6065054496285;
  matrix1(0, 3) = 0.586602877592668;
  matrix1(1, 3) = 10.6546861075331;
  matrix1(2, 3) = 4.33103069034405;
  matrix1(3, 3) = 8.75408579711802;

  matrix1.TestInverse(matrix1);
}

TEST(TestInverse, TestInverse7) {
  S21Matrix matrix1{7, 7};
  EXPECT_EQ(matrix1.get_cols(), 7);
  EXPECT_EQ(matrix1.get_rows(), 7);

  matrix1(0, 0) = 832;
  matrix1(0, 1) = -253;
  matrix1(0, 2) = -100;
  matrix1(0, 3) = -215;
  matrix1(0, 4) = -63;
  matrix1(0, 5) = -236;
  matrix1(0, 6) = -771;
  matrix1(1, 0) = 473;
  matrix1(1, 1) = 104;
  matrix1(1, 2) = -626;
  matrix1(1, 3) = 354;
  matrix1(1, 4) = -915;
  matrix1(1, 5) = -258;
  matrix1(1, 6) = -580;
  matrix1(2, 0) = -597;
  matrix1(2, 1) = 831;
  matrix1(2, 2) = -498;
  matrix1(2, 3) = -504;
  matrix1(2, 4) = 691;
  matrix1(2, 5) = 912;
  matrix1(2, 6) = -973;
  matrix1(3, 0) = 131;
  matrix1(3, 1) = -949;
  matrix1(3, 2) = -875;
  matrix1(3, 3) = 127;
  matrix1(3, 4) = -38;
  matrix1(3, 5) = -7;
  matrix1(3, 6) = 587;
  matrix1(4, 0) = 661;
  matrix1(4, 1) = 301;
  matrix1(4, 2) = -283;
  matrix1(4, 3) = -254;
  matrix1(4, 4) = -948;
  matrix1(4, 5) = -449;
  matrix1(4, 6) = 338;
  matrix1(5, 0) = -207;
  matrix1(5, 1) = -880;
  matrix1(5, 2) = -838;
  matrix1(5, 3) = 697;
  matrix1(5, 4) = 893;
  matrix1(5, 5) = -915;
  matrix1(5, 6) = -592;
  matrix1(6, 0) = 739;
  matrix1(6, 1) = 886;
  matrix1(6, 2) = 912;
  matrix1(6, 3) = 247;
  matrix1(6, 4) = -118;
  matrix1(6, 5) = -30;
  matrix1(6, 6) = -336;

  matrix1.TestInverse(matrix1);
}

TEST(TestInverse, TestInverse8) {
  S21Matrix matrix1{9, 9};
  EXPECT_EQ(matrix1.get_cols(), 9);
  EXPECT_EQ(matrix1.get_rows(), 9);

  matrix1(0, 0) = -929;
  matrix1(0, 1) = -332;
  matrix1(0, 2) = 313;
  matrix1(0, 3) = 190;
  matrix1(0, 4) = 287;
  matrix1(0, 5) = 44;
  matrix1(0, 6) = -468;
  matrix1(0, 7) = -381;
  matrix1(0, 8) = -397;
  matrix1(1, 0) = 961;
  matrix1(1, 1) = 371;
  matrix1(1, 2) = -532;
  matrix1(1, 3) = 842;
  matrix1(1, 4) = 87;
  matrix1(1, 5) = 92;
  matrix1(1, 6) = -40;
  matrix1(1, 7) = -356;
  matrix1(1, 8) = 822;
  matrix1(2, 0) = -469;
  matrix1(2, 1) = -55;
  matrix1(2, 2) = -426;
  matrix1(2, 3) = 282;
  matrix1(2, 4) = -706;
  matrix1(2, 5) = -270;
  matrix1(2, 6) = 912;
  matrix1(2, 7) = -823;
  matrix1(2, 8) = -769;
  matrix1(3, 0) = -612;
  matrix1(3, 1) = -924;
  matrix1(3, 2) = 327;
  matrix1(3, 3) = 454;
  matrix1(3, 4) = -29;
  matrix1(3, 5) = -366;
  matrix1(3, 6) = 724;
  matrix1(3, 7) = 775;
  matrix1(3, 8) = 897;
  matrix1(4, 0) = -775;
  matrix1(4, 1) = -36;
  matrix1(4, 2) = 9;
  matrix1(4, 3) = -955;
  matrix1(4, 4) = -289;
  matrix1(4, 5) = -594;
  matrix1(4, 6) = -735;
  matrix1(4, 7) = 475;
  matrix1(4, 8) = 993;
  matrix1(5, 0) = 89;
  matrix1(5, 1) = -156;
  matrix1(5, 2) = -834;
  matrix1(5, 3) = -102;
  matrix1(5, 4) = 465;
  matrix1(5, 5) = 626;
  matrix1(5, 6) = -649;
  matrix1(5, 7) = -828;
  matrix1(5, 8) = 248;
  matrix1(6, 0) = -660;
  matrix1(6, 1) = -400;
  matrix1(6, 2) = -30;
  matrix1(6, 3) = 740;
  matrix1(6, 4) = 374;
  matrix1(6, 5) = 473;
  matrix1(6, 6) = -654;
  matrix1(6, 7) = 684;
  matrix1(6, 8) = -153;
  matrix1(7, 0) = -374;
  matrix1(7, 1) = -892;
  matrix1(7, 2) = -316;
  matrix1(7, 3) = -811;
  matrix1(7, 4) = 789;
  matrix1(7, 5) = 222;
  matrix1(7, 6) = -985;
  matrix1(7, 7) = -248;
  matrix1(7, 8) = -440;
  matrix1(8, 0) = -869;
  matrix1(8, 1) = -758;
  matrix1(8, 2) = 332;
  matrix1(8, 3) = -572;
  matrix1(8, 4) = 105;
  matrix1(8, 5) = -548;
  matrix1(8, 6) = 925;
  matrix1(8, 7) = 137;
  matrix1(8, 8) = 739;

  matrix1.TestInverse(matrix1);
}

TEST(TestCalcComplements, TestCalcComplementsException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException2) {
  S21Matrix test_matrix(3, 2);

  EXPECT_EQ(test_matrix.get_rows(), 3);
  EXPECT_EQ(test_matrix.get_cols(), 2);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException3) {
  S21Matrix test_matrix(1, 5);

  EXPECT_EQ(test_matrix.get_rows(), 1);
  EXPECT_EQ(test_matrix.get_cols(), 5);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException4) {
  S21Matrix test_matrix(5, 1);

  EXPECT_EQ(test_matrix.get_rows(), 5);
  EXPECT_EQ(test_matrix.get_cols(), 1);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException5) {
  S21Matrix test_matrix(29, 30);

  EXPECT_EQ(test_matrix.get_rows(), 29);
  EXPECT_EQ(test_matrix.get_cols(), 30);

  FillMatrix(test_matrix, 1.99);
  CheckMatrix(test_matrix, 1.99);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverse10) {
  S21Matrix matrix1{16, 16};
  EXPECT_EQ(matrix1.get_cols(), 16);
  EXPECT_EQ(matrix1.get_rows(), 16);

  matrix1(0, 0) = -130;
  matrix1(0, 1) = 81;
  matrix1(0, 2) = -584;
  matrix1(0, 3) = 657;
  matrix1(0, 4) = 763;
  matrix1(0, 5) = 534;
  matrix1(0, 6) = 544;
  matrix1(0, 7) = -812;
  matrix1(0, 8) = -174;
  matrix1(0, 9) = -232;
  matrix1(0, 10) = -539;
  matrix1(0, 11) = -925;
  matrix1(0, 12) = 806;
  matrix1(0, 13) = -349;
  matrix1(0, 14) = 661;
  matrix1(0, 15) = 180;
  matrix1(1, 0) = 196;
  matrix1(1, 1) = -563;
  matrix1(1, 2) = -962;
  matrix1(1, 3) = 590;
  matrix1(1, 4) = 727;
  matrix1(1, 5) = 857;
  matrix1(1, 6) = 535;
  matrix1(1, 7) = 926;
  matrix1(1, 8) = -384;
  matrix1(1, 9) = 295;
  matrix1(1, 10) = 403;
  matrix1(1, 11) = -999;
  matrix1(1, 12) = 324;
  matrix1(1, 13) = -463;
  matrix1(1, 14) = -675;
  matrix1(1, 15) = -209;
  matrix1(2, 0) = -607;
  matrix1(2, 1) = -184;
  matrix1(2, 2) = -523;
  matrix1(2, 3) = -424;
  matrix1(2, 4) = 487;
  matrix1(2, 5) = -326;
  matrix1(2, 6) = 868;
  matrix1(2, 7) = 422;
  matrix1(2, 8) = 388;
  matrix1(2, 9) = -845;
  matrix1(2, 10) = -767;
  matrix1(2, 11) = -338;
  matrix1(2, 12) = -65;
  matrix1(2, 13) = -824;
  matrix1(2, 14) = -828;
  matrix1(2, 15) = 902;
  matrix1(3, 0) = 580;
  matrix1(3, 1) = 232;
  matrix1(3, 2) = 659;
  matrix1(3, 3) = -107;
  matrix1(3, 4) = -941;
  matrix1(3, 5) = 964;
  matrix1(3, 6) = -342;
  matrix1(3, 7) = 876;
  matrix1(3, 8) = 322;
  matrix1(3, 9) = 945;
  matrix1(3, 10) = -971;
  matrix1(3, 11) = 861;
  matrix1(3, 12) = -430;
  matrix1(3, 13) = -716;
  matrix1(3, 14) = -445;
  matrix1(3, 15) = 463;
  matrix1(4, 0) = 204;
  matrix1(4, 1) = 504;
  matrix1(4, 2) = 93;
  matrix1(4, 3) = -560;
  matrix1(4, 4) = 862;
  matrix1(4, 5) = -801;
  matrix1(4, 6) = 890;
  matrix1(4, 7) = -396;
  matrix1(4, 8) = 854;
  matrix1(4, 9) = 331;
  matrix1(4, 10) = 313;
  matrix1(4, 11) = 837;
  matrix1(4, 12) = -200;
  matrix1(4, 13) = 631;
  matrix1(4, 14) = -430;
  matrix1(4, 15) = -833;
  matrix1(5, 0) = 23;
  matrix1(5, 1) = 635;
  matrix1(5, 2) = -369;
  matrix1(5, 3) = 55;
  matrix1(5, 4) = 714;
  matrix1(5, 5) = -534;
  matrix1(5, 6) = 657;
  matrix1(5, 7) = 440;
  matrix1(5, 8) = -900;
  matrix1(5, 9) = -997;
  matrix1(5, 10) = 90;
  matrix1(5, 11) = -799;
  matrix1(5, 12) = -950;
  matrix1(5, 13) = 961;
  matrix1(5, 14) = 18;
  matrix1(5, 15) = -713;
  matrix1(6, 0) = 708;
  matrix1(6, 1) = 493;
  matrix1(6, 2) = -433;
  matrix1(6, 3) = -502;
  matrix1(6, 4) = -380;
  matrix1(6, 5) = -176;
  matrix1(6, 6) = -401;
  matrix1(6, 7) = 962;
  matrix1(6, 8) = 261;
  matrix1(6, 9) = -252;
  matrix1(6, 10) = 191;
  matrix1(6, 11) = 381;
  matrix1(6, 12) = 599;
  matrix1(6, 13) = -425;
  matrix1(6, 14) = -151;
  matrix1(6, 15) = -266;
  matrix1(7, 0) = 121;
  matrix1(7, 1) = 500;
  matrix1(7, 2) = 768;
  matrix1(7, 3) = 365;
  matrix1(7, 4) = -452;
  matrix1(7, 5) = 550;
  matrix1(7, 6) = -471;
  matrix1(7, 7) = 702;
  matrix1(7, 8) = -250;
  matrix1(7, 9) = 744;
  matrix1(7, 10) = -741;
  matrix1(7, 11) = 901;
  matrix1(7, 12) = 245;
  matrix1(7, 13) = 931;
  matrix1(7, 14) = 579;
  matrix1(7, 15) = -51;
  matrix1(8, 0) = 169;
  matrix1(8, 1) = 501;
  matrix1(8, 2) = 877;
  matrix1(8, 3) = -898;
  matrix1(8, 4) = -645;
  matrix1(8, 5) = -210;
  matrix1(8, 6) = 886;
  matrix1(8, 7) = 63;
  matrix1(8, 8) = -106;
  matrix1(8, 9) = 304;
  matrix1(8, 10) = -179;
  matrix1(8, 11) = 152;
  matrix1(8, 12) = 41;
  matrix1(8, 13) = 825;
  matrix1(8, 14) = -402;
  matrix1(8, 15) = 563;
  matrix1(9, 0) = 989;
  matrix1(9, 1) = -586;
  matrix1(9, 2) = 524;
  matrix1(9, 3) = 463;
  matrix1(9, 4) = -178;
  matrix1(9, 5) = -1000;
  matrix1(9, 6) = 825;
  matrix1(9, 7) = -833;
  matrix1(9, 8) = -600;
  matrix1(9, 9) = 261;
  matrix1(9, 10) = 352;
  matrix1(9, 11) = -706;
  matrix1(9, 12) = 333;
  matrix1(9, 13) = -296;
  matrix1(9, 14) = 537;
  matrix1(9, 15) = 975;
  matrix1(10, 0) = 74;
  matrix1(10, 1) = 703;
  matrix1(10, 2) = -969;
  matrix1(10, 3) = -80;
  matrix1(10, 4) = -938;
  matrix1(10, 5) = -653;
  matrix1(10, 6) = -723;
  matrix1(10, 7) = 697;
  matrix1(10, 8) = 690;
  matrix1(10, 9) = 229;
  matrix1(10, 10) = 696;
  matrix1(10, 11) = -166;
  matrix1(10, 12) = -500;
  matrix1(10, 13) = -924;
  matrix1(10, 14) = -430;
  matrix1(10, 15) = -22;
  matrix1(11, 0) = 626;
  matrix1(11, 1) = -350;
  matrix1(11, 2) = 530;
  matrix1(11, 3) = 134;
  matrix1(11, 4) = -387;
  matrix1(11, 5) = -172;
  matrix1(11, 6) = -184;
  matrix1(11, 7) = 602;
  matrix1(11, 8) = -557;
  matrix1(11, 9) = 715;
  matrix1(11, 10) = 650;
  matrix1(11, 11) = 587;
  matrix1(11, 12) = 570;
  matrix1(11, 13) = -507;
  matrix1(11, 14) = 1;
  matrix1(11, 15) = 892;
  matrix1(12, 0) = -21;
  matrix1(12, 1) = 839;
  matrix1(12, 2) = -547;
  matrix1(12, 3) = 191;
  matrix1(12, 4) = -914;
  matrix1(12, 5) = 265;
  matrix1(12, 6) = -559;
  matrix1(12, 7) = 226;
  matrix1(12, 8) = 911;
  matrix1(12, 9) = -453;
  matrix1(12, 10) = -604;
  matrix1(12, 11) = -551;
  matrix1(12, 12) = 954;
  matrix1(12, 13) = -457;
  matrix1(12, 14) = 384;
  matrix1(12, 15) = 297;
  matrix1(13, 0) = 822;
  matrix1(13, 1) = -692;
  matrix1(13, 2) = -883;
  matrix1(13, 3) = 490;
  matrix1(13, 4) = -178;
  matrix1(13, 5) = 55;
  matrix1(13, 6) = 380;
  matrix1(13, 7) = 659;
  matrix1(13, 8) = -123;
  matrix1(13, 9) = 53;
  matrix1(13, 10) = 135;
  matrix1(13, 11) = 421;
  matrix1(13, 12) = -242;
  matrix1(13, 13) = -343;
  matrix1(13, 14) = 449;
  matrix1(13, 15) = -349;
  matrix1(14, 0) = 449;
  matrix1(14, 1) = -737;
  matrix1(14, 2) = 592;
  matrix1(14, 3) = -292;
  matrix1(14, 4) = -873;
  matrix1(14, 5) = -703;
  matrix1(14, 6) = -633;
  matrix1(14, 7) = -312;
  matrix1(14, 8) = 989;
  matrix1(14, 9) = -950;
  matrix1(14, 10) = 961;
  matrix1(14, 11) = -403;
  matrix1(14, 12) = -937;
  matrix1(14, 13) = 652;
  matrix1(14, 14) = 45;
  matrix1(14, 15) = -26;
  matrix1(15, 0) = 740;
  matrix1(15, 1) = 21;
  matrix1(15, 2) = -463;
  matrix1(15, 3) = 692;
  matrix1(15, 4) = -937;
  matrix1(15, 5) = -833;
  matrix1(15, 6) = -232;
  matrix1(15, 7) = 987;
  matrix1(15, 8) = -968;
  matrix1(15, 9) = 778;
  matrix1(15, 10) = 934;
  matrix1(15, 11) = 731;
  matrix1(15, 12) = -516;
  matrix1(15, 13) = -744;
  matrix1(15, 14) = 986;
  matrix1(15, 15) = 88;

  matrix1.TestInverse(matrix1);
}
