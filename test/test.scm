;;;
;;; Test zinnia
;;;

(use gauche.test)
(use gauche.interactive)
(use gauche.charconv)
(use file.util)
(use sxml.ssax)
(use sxml.sxpath)
(use sxml.tools)

(test-start "zinnia")
(use zinnia)
(test-module 'zinnia)

;; The following is a dummy test code.
;; Replace it for your tests.

(test* "0.06" "0.06" (zinnia-version))
(define recognizer (zinnia-recognizer-new))
(d (zinnia-recognizer-open recognizer (sys-realpath "handwriting-ja.model")))
(d (zinnia-recognizer-strerror recognizer))
(define character (zinnia-character-new))
(zinnia-character-clear character)
;; (zinnia-character-set-width character 300)
;; (zinnia-character-set-height character 300)
;; (zinnia-character-add character 0 51 29)
;; (zinnia-character-add character 0 117 41)
;; (zinnia-character-add character 1 99 65)
;; (zinnia-character-add character 1 219 77)
;; (zinnia-character-add character 2 27 131)
;; (zinnia-character-add character 2 261 131)
;; (zinnia-character-add character 3 129 17)
;; (zinnia-character-add character 3 57 203)
;; (zinnia-character-add character 4 111 71)
;; (zinnia-character-add character 4 219 173)
;; (zinnia-character-add character 5 81 161)
;; (zinnia-character-add character 5 93 281)
;; (zinnia-character-add character 6 99 167)
;; (zinnia-character-add character 6 207 167)
;; (zinnia-character-add character 6 189 245)
;; (zinnia-character-add character 7 99 227)
;; (zinnia-character-add character 7 189 227)
;; (zinnia-character-add character 8 111 257)
;; (zinnia-character-add character 8 189 245)
(zinnia-character-parse character "(character (width 1000)(height 1000)(strokes ((180 193)(830 226))((490 33)(483 670)(606 840))((746 343)(496 766)(273 800)(176 680)(286 496)(606 463)(800 573)(826 746)(760 833))))")

(define r (zinnia-recognizer-classify recognizer character 10))
(d r)
(d (zinnia-result-size r))
(print (ces-convert (zinnia-result-value r 0) "*JP" "SJIS"))
(d (zinnia-result-score r 0))
(print (ces-convert (zinnia-result-value r 1) "*JP" "SJIS"))
(d (zinnia-result-score r 1))
(print (ces-convert (zinnia-result-value r 9) "*JP" "SJIS"))
(d (zinnia-result-score r 9))

(define sxml (call-with-input-file (sys-realpath "test/data/a.xml") (lambda (port) (ssax:xml->sxml port '()))))
(d (cdar ((sxpath "PAGE/ELEMENTS/stroke[1]/x") sxml)))
(d (cdar ((sxpath "PAGE/ELEMENTS/stroke[1]/y") sxml)))

;; epilogue
(test-end)





