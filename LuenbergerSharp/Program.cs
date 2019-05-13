using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MathNet.Numerics.LinearAlgebra;
using MathNet.Numerics.LinearAlgebra.Double;

namespace LuenbergerSharp
{
	class Program
	{
		static void Main(string[] args)
		{
			Matrix<double> A = DenseMatrix.OfArray(new double[,] {
				{0, 0, 0, 0, 0, 0},
				{-2000, -1.2, 0, 0, 20, 0},
				{0, 0, 0, 1.0, 0, 0},
				{163.9341, 0, -163.9341, 0, 0, -1.6393},
				{0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0}});
			Matrix<double> B = DenseMatrix.OfArray(new double[,]
			{
				{0},
				{0},
				{0},
				{27.8688},
				{0},
				{0}});
			Matrix<double> C = DenseMatrix.OfArray(new double[,] {
				{100, 0, -100, 0, 0, 0},
				{0, 0, 0, 17, 0, 0}
			});
			Matrix<double> L = DenseMatrix.OfArray(new double[,] {
				{1.0, 10.0},
				{51.0, 0541},
				{0, 13},
				{24, 870},
				{59, 489},
				{-324, -10508},
			});

			Matrix<double> U = DenseMatrix.OfArray(new double[,] { {0.5} });
			Matrix<double> Y = DenseMatrix.OfArray(new double[,] { {0.7}, {0} });
			Matrix<double> X = DenseMatrix.OfArray(new double[,] {
				{0},
				{0},
				{0},
				{0},
				{0},
				{0}});
			Matrix<double> X_prev = DenseMatrix.OfArray(new double[,] {
				{0},
				{0},
				{0},
				{0},
				{0},
				{0}});

			for(int i = 0; i < 30; i++)
			{
				X = LuenbergerObserver(U, Y, ref X_prev, A, B, C, L);
				System.Console.WriteLine(X[0, 0]);
			}

		}

		public static Matrix<double> LuenbergerObserver(Matrix<double> U, Matrix<double> Y, ref Matrix<double> X_prev,Matrix<double> A, Matrix<double> B, Matrix<double> C, Matrix<double> L)
		{
			var res = A * X_prev + B * U + L * (Y - (C * X_prev));

			X_prev = res;

			return res;
		}
	}
}
