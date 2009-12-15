;;;
;;; Test zinnia
;;;

(use gauche.test)

(test-start "zinnia")
(use zinnia)
(test-module 'zinnia)

;; The following is a dummy test code.
;; Replace it for your tests.
(test* "test-zinnia" "zinnia is working"
       (test-zinnia))

(test* "0.5" "0.5" (zinnia-version))
;; epilogue
(test-end)





