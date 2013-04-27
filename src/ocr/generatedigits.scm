

(define (draw-digit-image digit font size-px filename)
  (let* ((img (car (gimp-image-new 100 100 GRAY)))
         (layer (car (gimp-layer-new img 100 100 GRAY-IMAGE "firstLayer" 100 NORMAL-MODE))))
    (gimp-image-insert-layer img layer 0 0)
    (gimp-context-set-foreground '(255 255 255))
    (gimp-edit-bucket-fill layer 0 0 100 255 TRUE 0 0)
    (gimp-context-set-foreground '(0 0 0))
    (let* ((textlayer (car (gimp-text-fontname img layer
                                               20 20
                                               (number->string digit)
                                               0
                                               TRUE
                                               size-px PIXELS
                                               font)))
           (result (car (gimp-image-flatten img))))
      (gimp-file-save RUN-NONINTERACTIVE img result filename filename))))


(for-each
 (lambda (font) 
   (for-each 
    (lambda (digit)
      (let* ((str-num (number->string digit)))
        (draw-digit-image digit 
                          font 
                          30 
                          (string-append "train/" 
                                         str-num "/"
                                         str-num "-" font ".png"))))
    '(1 2 3 4 5 6 7 8 9 0)))
 (cadr (gimp-fonts-get-list "")))


(gimp-quit TRUE)

