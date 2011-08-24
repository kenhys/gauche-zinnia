;;;
;;; Test zinnia
;;;

(use gauche.test)

(test-start "zinnia")
(use zinnia)
(test-module 'zinnia)

;; The following is a dummy test code.
;; Replace it for your tests.

(test* "0.06" "0.06" (zinnia-version))
;; epilogue
(test-end)





