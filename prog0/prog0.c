#include <cairo.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *filename;     // The name of the output photo image
    int dim_x = 0;      // Width of the image
    int dim_y = 0;      // Height of the image
    int rec = 0;        // Resursive depth 
    double frac = 0;    // Fraction
    double start_x = 0; // Starting x coordinate
    double start_y = 0; // Starting y coordinate
    double end_x = 0;   // Ending x coordinate
    double end_y = 0;   // Ending y coordinate
    scanf("%s%d%d%d%lf%lf%lf%lf%lf", filename, &dim_x, &dim_y, &rec, &frac, &start_x, &start_y,
        &end_x, &end_y); // Lazy way for reading from 

    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, dim_x, dim_y);
    cairo_t *cr = cairo_create(surface);

    cairo_set_source_rgb(cr, 0, 1, 0); // green
    cairo_move_to(cr, 0, 0); // top left corner
    cairo_line_to(cr, 256, 256); // middle of the image
    cairo_move_to(cr, 256, 0);
    cairo_line_to(cr, 0, 256);
    cairo_set_line_width(cr, 10.0);
    cairo_stroke(cr);

    cairo_set_source_rgb(cr, 0, 0, 1); // blue
    cairo_rectangle(cr, 0, 255, 255, 255);
    cairo_fill(cr);

    cairo_move_to(cr, 0, 255);
    cairo_line_to(cr, 255, 255);
    cairo_line_to(cr, 255, 511);
    cairo_line_to(cr, 0, 511);
    cairo_close_path(cr);

    cairo_set_source_rgb(cr, 1, 1, 1); // white
    cairo_set_line_width(cr, 8.0);
    cairo_stroke(cr);

    cairo_set_source_rgb(cr, 1, 1, 1); // white
    cairo_rectangle(cr, 256, 256, 511, 511);
    cairo_fill(cr);

    cairo_move_to(cr, 256, 256);
    cairo_rel_line_to(cr, 256, 0);
    cairo_rel_line_to(cr, 0, 256);
    cairo_rel_line_to(cr, -256, 0);
    cairo_close_path(cr);

    cairo_set_source_rgb(cr, 1, 0, 0); // red
    cairo_set_line_width(cr, 5.5);
    cairo_stroke(cr);

    cairo_destroy(cr);
    cairo_surface_write_to_png(surface, filename);
    cairo_surface_destroy(surface);
    exit(0);
}
