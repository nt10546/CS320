; Nam Tran
; p6.scm
;
; A couple of scheme/racket functions to manipulate lists
;  and show tail recursion
; All functions check to see if input is a list

; #lang racket
; (require racket/trace)

; Helper functions
; Reverse function
;  Outputs a list of the reversed inputted list
;  Does recursive swaps from the end of the original list
(define (reverse lst)
  (cond
    ((null? lst) lst)
    ((null? (rest lst)) lst)
    (else
      (cons (first (reverse (rest lst)))
            (reverse (cons (first lst)
                       (reverse (rest (reverse (rest lst)))))))))
  )

; Testing lists
(define list0 (list 'j 'k 'l 'm 'n 'o 'j))
(define list1 (list 'a 'b 'c 'd 'e 'f 'g))
(define list2 (list 's 't 'u 'v 'w 'x 'y 'z))
(define list3 (list 'j 'k 'l 'm 'l 'k 'j))
(define list4 (list 'n 'o 'p 'q 'q 'p 'o 'n))
(define list5 '((a b) c (d e d) c (a b)))
(define list6 '((h i) (j k) l (m n))) 
(define list7 '(f (a b) c (d e d) (b a) f))
(define list8 (list 1 2 3 4 5 6 7 8 9 10))

; Odds function
;  Outputs the odd elements of the list
(define (odds lst)
  (cond
    ((list? lst)
         (cond
           ((null? lst) '())
               ((null? (cdr lst)) (list (car lst)))
               (else (cons (car lst) (odds (cddr lst))))
 ))
        (error (println "Usage: (odds list)")))
  )
; Evenrev function
;  Outputs the even elements of the list reversed
(define (evenrev lst)
  (cond
    ((list? lst)
         (reverse (evens lst)))
        (error (println "Usage: (evenrev list)")))
  )

; Even function
;  Outputs the even elements of the list
(define (evens lst)
         (cond
           ((null? lst) '())
               ((eq? (cdr lst) '()) '())
               (else (cons (cadr lst) (evens (cddr lst)))))
  )


; Penultimate function
;  Outputs the second to last element of the list
(define (penultimate lst)
  (cond
    ((list? lst)
     (cond
           ((eq? (length lst) 2) (car lst))
               (else (penultimate (cdr lst)))))
    (error (println "Usage: (penultimate list)")))
  )

; Palindrome function
;  Outputs #t if the list is a palindrome
;  Outputs #f if the list is not a palindrome
(define (palindrome lst)
  (cond
    ((list? lst) (equal? lst (reverse lst)))
    (error (println "Usage: (palindrome list)")))
  )
