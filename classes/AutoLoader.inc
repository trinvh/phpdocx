<?php

/**
 * Autoloader
 *
 * @category   Phpdocx
 * @package    loader
 * @copyright  Copyright (c) Narcea Producciones Multimedia S.L.
 *             (http://www.2mdc.com)
 * @license    http://www.phpdocx.com/wp-content/themes/lightword/pro_license.php
 * @version    2014.04.09
 * @link       http://www.phpdocx.com
 */
class AutoLoader
{

    /**
     * Main tags of relationships XML
     *
     * @access public
     * @static
     */
    public static function load()
    {
        spl_autoload_register(array('AutoLoader', 'autoloadGenericClasses'));
        spl_autoload_register(array('AutoLoader', 'autoloadLog4php'));
        spl_autoload_register(array('AutoLoader', 'autoloadPdf'));
        spl_autoload_register(array('AutoLoader', 'autoloadMht'));
    }

    /**
     * Autoload dompdf
     *
     * @access public
     * @param string $className Class to load
     */
    public static function autoloadDompdf($className)
    {
        
    }

    /**
     * Autoload phpdocx
     *
     * @access public
     * @param string $className Class to load
     */
    public static function autoloadGenericClasses($className)
    {
        $pathPhpdocx = dirname(__FILE__) . '/' . $className . '.inc';
        if (file_exists($pathPhpdocx)) {
            $arrayClassesEnc = array(
                'CreateDocx',
                'AutoLoader',
                'Phpdocx_config',
                'CreateElement',
                'Helpers',
            );
            if (in_array($className, $arrayClassesEnc)) {
                require_once $pathPhpdocx;
            } else {
                eval (gzinflate(base64_decode(file_get_contents($pathPhpdocx))));
            }
        }
    }

    /**
     * Autoload log4php
     *
     * @access public
     * @param string $className Class to load
     */
    public static function autoloadLog4php($className)
    {
        $pathLogphp = dirname(__FILE__) . '/../lib/log4php/'
                . $className . '.php';
        if (file_exists($pathLogphp)) {
            require_once $pathLogphp;
        }

        $pathLogphpAppenders = dirname(__FILE__) . '/../lib/log4php/appenders/'
                . $className . '.php';
        if (file_exists($pathLogphpAppenders)) {
            require_once $pathLogphpAppenders;
        }

        $pathLogphpConfigurators = dirname(__FILE__) . '/../lib/log4php/configurators/'
                . $className . '.php';
        if (file_exists($pathLogphpConfigurators)) {
            require_once $pathLogphpConfigurators;
        }

        $pathLogphpFilters = dirname(__FILE__) . '/../lib/log4php/filters/'
                . $className . '.php';
        if (file_exists($pathLogphpFilters)) {
            require_once $pathLogphpFilters;
        }

        $pathLogphpHelpers = dirname(__FILE__) . '/../lib/log4php/helpers/'
                . $className . '.php';
        if (file_exists($pathLogphpHelpers)) {
            require_once $pathLogphpHelpers;
        }

        $pathLogphpLayouts = dirname(__FILE__) . '/../lib/log4php/layouts/'
                . $className . '.php';
        if (file_exists($pathLogphpLayouts)) {
            require_once $pathLogphpLayouts;
        }

        $pathLogphpPattern = dirname(__FILE__) . '/../lib/log4php/pattern/'
                . $className . '.php';
        if (file_exists($pathLogphpPattern)) {
            require_once $pathLogphpPattern;
        }

        $pathLogphpRenderers = dirname(__FILE__) . '/../lib/log4php/renderers/'
                . $className . '.php';
        if (file_exists($pathLogphpRenderers)) {
            require_once $pathLogphpRenderers;
        }

        $pathLogphpXml = dirname(__FILE__) . '/../lib/log4php/xml/'
                . $className . '.php';
        if (file_exists($pathLogphpXml)) {
            require_once $pathLogphpXml;
        }
    }

    /**
     * Autoload mht
     *
     * @access public
     * @param string $className Class to load
     */
    public static function autoloadMht($className)
    {
        $pathMht = dirname(__FILE__) . '/../lib/'
                . $className . '.php';
        if (file_exists($pathMht)) {
            require_once $pathMht;
        }
    }

    /**
     * Autoload PDF libraries
     *
     * @access public
     * @param string $className Class to load
     */
    public static function autoloadPdf($className)
    {
        $pathPDF = dirname(__FILE__) . '/../lib/pdf/' . $className . '.inc';
        if (file_exists($pathPDF)) {
            require_once $pathPDF;
        }
        $pathDOMPDF = dirname(__FILE__) . '/../lib/pdf/dompdf_config.inc.php';
        if (file_exists($pathDOMPDF)) {
            require_once $pathDOMPDF;
        }
        $pathTCPDF = dirname(__FILE__) . '/../lib/pdf/tcpdf/tcpdf.php';
        if (file_exists($pathTCPDF)) {
            require_once $pathTCPDF;
        }
        $pathMainTCPDF = dirname(__FILE__) . '/../lib/pdf/class.tcpdf.php';
        if (file_exists($pathMainTCPDF)) {
            require_once $pathMainTCPDF;
        }
        $pathFPDI = dirname(__FILE__) . '/../lib/fpdi/fpdi.php';
        if (file_exists($pathFPDI)) {
            require_once $pathFPDI;
        }
    }

}
