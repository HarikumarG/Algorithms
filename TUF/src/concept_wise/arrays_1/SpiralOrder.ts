// Given an M * N matrix, print the elements in a clockwise spiral manner.
// Return an array with the elements in the order of their appearance when printed in a spiral manner.
// eg. [[1, 2, 3], [4 ,5 ,6], [7, 8, 9]] =  [1, 2, 3, 6, 9, 8, 7, 4, 5]

export default class SpiralOrder {

   // store members
   private matrix: Array<Array<number>> = [[]];
   private spiralOrder: Array<number> = [];
   private n: number = 0; // refers to columns
   private m: number = 0; // refers to rows

   // processing members
   private left = 0;
   private top = 0;
   private right = 0;
   private bottom = 0;
   

   constructor(mat: Array<Array<number>>) {
      this.matrix = mat.map(row => row.slice());
      this.n = this.matrix.length;
      this.m = this.matrix[0].length;

      this.left = 0;
      this.top = 0;
      this.right = this.m-1; 
      this.bottom = this.n-1;
   }

   private build(): void {

      while (this.top <= this.bottom && this.left <= this.right) {
         for (let i = this.left; i <= this.right; i++)
            this.spiralOrder.push(this.matrix[this.top][i]);
         this.top++;

         for (let i = this.top; i <= this.bottom; i++)
            this.spiralOrder.push(this.matrix[i][this.right]);
         this.right--;

         if (this.top <= this.bottom) {
            for (let i = this.right; i >= this.left; i--)
               this.spiralOrder.push(this.matrix[this.bottom][i]);
            this.bottom--;
         }

         if (this.left <= this.right) {
            for (let i = this.bottom; i >= this.top; i--)
               this.spiralOrder.push(this.matrix[i][this.left]);
            this.left++;
         }
      }
   }

   getSpiralOrder(): Array<number> {
      this.build();
      return this.spiralOrder;
   }
}