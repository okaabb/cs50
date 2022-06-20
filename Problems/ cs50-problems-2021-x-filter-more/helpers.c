#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double color = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            if ((color - (int)color) >= 0.5)
            {
                color = (int)color + 1;
            }
            else 
            {
                color = (int)color;
            }
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = color;
        }
    } 
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    } 
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, jj = width - 1; j < width; j++, jj--)
        {
            image[i][j] = temp[i][jj];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    int dirx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int diry[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double cnt = 1.0;
            double colorb = temp[i][j].rgbtBlue;
            double colorg = temp[i][j].rgbtGreen;
            double colorr = temp[i][j].rgbtRed;
            for (int k = 0; k < 8; k++)
            {
                int newx = i + dirx[k];
                int newy = j + diry[k];
                if (newx < height && newy < width && newx >= 0 && newy >= 0)
                {
                    cnt++;
                    colorb += temp[newx][newy].rgbtBlue;
                    colorg += temp[newx][newy].rgbtGreen;
                    colorr += temp[newx][newy].rgbtRed;
                }
            }
            colorb /= cnt;
            colorg /= cnt;
            colorr /= cnt;
            
            if ((colorb - (int)colorb) >= 0.5)
            {
                colorb = (int)colorb + 1;
            }
            else 
            {
                colorb = (int)colorb;
            }
            
            if ((colorg - (int)colorg) >= 0.5)
            {
                colorg = (int)colorg + 1;
            }
            else 
            {
                colorg = (int)colorg;
            }
            
            if ((colorr - (int)colorr) >= 0.5)
            {
                colorr = (int)colorr + 1;
            }
            else 
            {
                colorr = (int)colorr;
            }
            
            image[i][j].rgbtBlue = colorb;
            image[i][j].rgbtGreen = colorg;
            image[i][j].rgbtRed = colorr;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    
    int dirx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int diry[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int gx[8] = {-1, 0, 1, -2, 2, -1, 0, 1};
    int gy[8] = {-1, -2, -1, 0, 0, 1, 2, 1};
    
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        { 
            double colorbx = 0, colorby = 0, colorgx = 0, colorgy = 0, colorrx = 0, colorry = 0;
            
            for (int k = 0; k < 8; k++)
            {
                int newx = i + dirx[k];
                int newy = j + diry[k];
                if (newx < height && newy < width && newx >= 0 && newy >= 0)
                {
                    colorrx += ((temp[newx][newy].rgbtRed * gx[k]));
                    colorry += ((temp[newx][newy].rgbtRed * gy[k]));
                    
                    colorbx += ((temp[newx][newy].rgbtBlue * gx[k]));
                    colorby += ((temp[newx][newy].rgbtBlue * gy[k]));
                    
                    colorgx += ((temp[newx][newy].rgbtGreen * gx[k]));
                    colorgy += ((temp[newx][newy].rgbtGreen * gy[k]));
                }
            }
            colorrx *= colorrx;
            colorry *= colorry;
            
            colorgx *= colorgx;
            colorgy *= colorgy;
            
            colorbx *= colorbx;
            colorby *= colorby;
            
        
            double totalRed = 0, totalGreen = 0, totalBlue = 0;
            
            totalRed = sqrt((colorrx) + (colorry));
            totalGreen = sqrt((colorgx) + (colorgy));
            totalBlue = sqrt((colorbx) + (colorby));
            
            if (totalRed > 255.0)
            {
                totalRed = 255;
            }
            
            if (totalRed < 0)
            {
                totalRed = 0;
            }
        
            if (totalBlue > 255.0)
            {
                totalBlue = 255;
            }

            if (totalBlue < 0)
            {
                totalBlue = 0;
            }
            
            if (totalGreen > 255.0)
            {
                totalGreen = 255;
            }
            
            if (totalGreen < 0)
            {
                totalGreen = 0;
            }
            
            if ((totalBlue - (int)totalBlue) >= 0.5)
            {
                totalBlue = (int)totalBlue + 1;
            }
            else 
            {
                totalBlue = (int)totalBlue;
            }
            if ((totalRed - (int)totalRed) >= 0.5)
            {
                totalRed = (int)totalRed + 1;
            }
            else 
            {
                totalRed = (int)totalRed;
            }
            if ((totalGreen - (int)totalGreen) >= 0.5)
            {
                totalGreen = (int)totalGreen + 1;
            }
            else 
            {
                totalGreen = (int)totalGreen;
            }
            
            image[i][j].rgbtBlue = totalBlue;
            image[i][j].rgbtGreen = totalGreen;
            image[i][j].rgbtRed = totalRed;
            
        }
        
    }
    return;
}
